# Graph / FPS optimization plan

この文書は、concepts の導入後に graph と FPS の実装を整理・最適化するための作業メモである。
まず API と型の境界を固め、その後にデータ構造・アルゴリズムの最適化を行う。

## 方針

- 既存の利用コードを大きく壊さず、concept をアルゴリズムの要求仕様として使う。
- dense / sparse は実行時に選択する。dense 用・sparse 用の型を分けることは当面行わない。
- SPS (Set Power Series) は専用アルゴリズムが多いため、通常の FPS と別カテゴリとして扱う。
- 最適化の前に benchmark と unit test を追加し、速度だけでなく結果とメモリ使用量も比較する。

## Graph

### 現状の確認事項

- `type_traits/graph.hpp` の `Graph` は、`value_type`、複数の静的フラグ、`operator[]`、`edges` を同時に要求している。
  そのため edge list だけを読む Warshall-Floyd のようなアルゴリズムにも、不要な隣接アクセスが要求される。
- `AdjacencyList`、`StaticAdjacencyList`、`AdjacencyMatrix` は同じ graph API を目指しているが、隣接要素の型が異なる。
  特に adjacency matrix の `_pair` は `from` / `to` を持たず、1セルに1辺しか保持できないため、現在の `Edge` 系 concept や多重辺 graph とは自然に一致しない。
- dynamic adjacency list は頂点ごとの `vector`、static adjacency list は CSR に近い配列を使っている。
- `StaticAdjacencyList::build()` は `head` を累積和に変換するため、build 後の再利用・再構築の扱いを明確にする必要がある。
- いくつかのアルゴリズムは concept で制約されている一方、`g.edges` や edge id の内部表現に直接依存している。

### 型・concept の整理

1. 最小限の capability に分割する。

   - vertex count / edge count
   - vertex adjacency range
   - edge の `from`, `to`, `id`
   - edge の `cost`
   - edge list
   - directed / undirected
   - static storage
   - simple graph / multigraph

2. `Graph` を「全てのメンバを持つ具体的な graph 型」ではなく、アルゴリズムが必要とする最小 concept として再定義する。
   vertex count と edge list だけを持つ graph を表現できるようにし、adjacency access を必須にしない。

3. edge list を使うアルゴリズム向けに、adjacency を要求しない concept を用意する。
   Warshall-Floyd、Bellman-Ford、MST などは、`VertexCount` と `EdgeList`、必要なら `WeightedEdge` だけを要求する。
   `WeightedEdgeListGraph` が `Graph` を経由して隣接 access を要求している構造は見直す。

4. adjacency matrix は edge と同じ型を無理に要求せず、matrix entry 用の concept または graph view を用意する。
   simple graph 用の matrix と、多重辺を保持できる matrix を別の型または capability として扱う。
   多重辺を1セルにまとめる場合は、最小値・最後に追加した辺などの重複辺ポリシーを型の仕様にする。

5. `WeightedGraph` などの合成 concept は、実際に `cost` を読むアルゴリズムだけで使用する。
   `template <WeightedGraph G>` の形式を基本にし、関数本体内の `requires` を減らす。

6. concept の unit test を追加する。
   標準の `vector<vector<int>>`、edge list only の graph、dynamic adjacency list、static adjacency list、simple matrix、多重辺 matrix、最小限の自作 graph view を対象に、意図した適合・不適合を `static_assert` で確認する。

### データ構造・入力の最適化

- static adjacency list は `head` の構築前後を分離し、二重 build や再構築時の破壊的な状態変化を防ぐ。
- static graph の read-only traversal は iterator / `std::span` 相当の軽量 view を返し、毎回の一時オブジェクト生成を避ける。
- dynamic adjacency list は edge 数が分かる場合に reserve し、入力時の再確保を減らす。
- `edges` のコピーが不要なアルゴリズムでは参照または view を使う。MST のようにソートが必要な場合だけ明示的にコピーする。
- edge id と `edges` の index が一致するという前提を concept / documentation / assertion で明確にする。
- adjacency matrix は `O(V^2)` のメモリを必要とするため、利用箇所を行列演算向けに限定し、一般 graph algorithm の入力に暗黙変換しない。
- adjacency matrix は単純 graph 用と多重辺 graph 用を分ける。多重辺を扱う型では、セルを edge の集合にするか、明示的な集約関数を保持する。
- edge list only の graph では adjacency list を構築せず、入力された `edges` をそのままアルゴリズムへ渡せるようにする。

### アルゴリズム側の整理

- BFS、Dijkstra、SCC、lowlink、tree algorithms について、隣接 access が必要な範囲に concept を限定する。
- Warshall-Floyd、Bellman-Ford、MST について、edge list only の入力で動作する concept に分離する。
- edge list が不要なアルゴリズムから `g.edges` 依存を除く。
- 重みの型、距離の型、無限大の表現を分離し、`value_type` を距離型として暗黙利用しない箇所を確認する。
- DFS の再帰深さ、priority queue の stale entry、不要な `vector` 初期化・コピーを benchmark で確認する。
- graph view を導入する場合、元の graph の所有権を持たず、アルゴリズムの引数で一時 view を安全に渡せる形にする。

## FPS

### 現状の確認事項

- `FormalPowerSeriesBase` は `std::vector<mint>` を基礎にした dense representation である。
- `FPSNTT` と `FPSArb` は modulus category を型で区別できている。
- ordinary / EGF / SPS、univariate / bivariate / multivariate の category は導入済みだが、アルゴリズム側での利用はまだ限定的である。
- `log`、`pow`、`inv`、`exp` は dense / sparse の選択をコメントで示しつつ、現在は dense 実装を呼ぶ。
- `fps_sparsity_detector.hpp` は各回の係数を走査し、固定係数によるヒューリスティックで dense / sparse を選ぶ。
- convolution は NTT-friendly と arbitrary modulus の実装で分かれているが、sparsity detector に `bool is_ntt_friendly` を渡している。

### 型・concept の整理

1. modulus category は既存の `NTTFriendlyFormalPowerSeries` / `ArbitraryModulusFormalPowerSeries` を基礎にする。

2. `ConvolvableFPS`、`InvertibleFPS`、`ExpFPS` など、アルゴリズムの前提となる operation concept を必要に応じて追加する。
   「FPS である」ことと「NTT による exp が可能」であることを一つの concept に詰め込まない。

3. SPS、EGF、multivariate は通常の univariate ordinary FPS と異なる前提を持つため、該当アルゴリズムの template parameter に明示する。

4. dense / sparse は型ではなく runtime dispatch とする。ユーザーが同じ FPS 型を使ったまま、入力の疎密に応じてアルゴリズムを選べることを優先する。

### sparsity check の改善

- detector の `bool is_ntt_friendly` を modulus concept または FPS の static category から導出する。
- convolution、log、exp、inv、pow ごとにコストモデルを分ける。現在の係数を共用した固定式ではなく、実際の実装コストと benchmark 結果から閾値を決める。
- 毎回全係数を走査するコストを測定する。
  必要であれば非零係数数の lazy cache、明示的な `sparsity_hint`、または sparse index の一時生成を検討する。
- ただし係数の直接変更を許しているため、キャッシュを導入する場合は invalidation の仕様を先に決める。
- sparse convolution / sparse log / sparse exp / sparse pow の各実装で、同じ係数列を何度も走査・構築していないか確認する。
- 係数の末尾の zero、先頭 zero、要求次数 `deg` の扱いを共通化し、不要な resize / copy を減らす。

### 演算実装の最適化

- NTT-friendly FPS は butterfly buffer の確保、transform の再利用、`a == b` 判定後のコピーを benchmark する。
- arbitrary modulus convolution は CRT / Garner 用の一時配列と FPS コピーを減らす。
- `dense_inv`、`dense_exp`、`dense_log` の反復ごとの一時 FPS を削減できるか確認する。
- `FormalPowerSeriesBase` の `operator>>=`, `operator<<=`, `pre`, `rev` などで、move と resize を活用して不要な allocation を減らす。
- multivariate FPS の `base` 表現と truncated convolution が、入力サイズに対して過剰な配列を確保していないか測定する。
- SPS 専用アルゴリズムは通常 FPS の sparse dispatch に無理に統合せず、専用 API として整理する。

## 作業順序

1. 現行実装の benchmark と concept unit test を追加する。
2. graph concept を capability 単位に整理し、既存 graph 型が全て通る状態を作る。
3. graph の static storage / input / edge view を整理する。ここではアルゴリズムの結果を変えない。
4. graph algorithms の template parameter と不要なコピーを見直す。
5. FPS の operation concept と modulus dispatch を整理する。
6. sparsity detector のコストモデルを benchmark ベースで見直す。
7. NTT、arbitrary convolution、dense / sparse FPS operations の allocation を最適化する。
8. verify と benchmark を実行し、速度・メモリ・結果を比較する。

## 当面の非目標

- graph の storage type を一度に全面変更しない。
- dense FPS / sparse FPS の公開型を新設しない。
- concept の導入と同時にアルゴリズムの仕様を変更しない。
- benchmark で根拠を取る前に、固定閾値や magic number を増やさない。
