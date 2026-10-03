---
title: Power Sum
documentation_of: //math_mod/power_sum.hpp
---

標本点から多項式の和と，等比数列で重み付けした和を計算する．$0^0$は$1$として扱う．

## 冪和

### `sum_of_monomial` {#sum-of-monomial}

#### 宣言

```cpp
template <modint::Modular mint, UnsignedIntegral T1, UnsignedIntegral T2>
mint sum_of_monomial(T1 n, T2 k);
```

#### 概要

非負整数$n$と$k$を受け取り，次の値を返す．

$$
\sum_{i=0}^{n-1}i^k
$$

#### アルゴリズム

[`pow_table`](https://kk2a.github.io/library/math/multiplicative_function/pow_table.hpp.html)で$0^k,1^k,\ldots,k^k$を列挙し，その累積和を
[`sample_point_evaluate`](https://kk2a.github.io/library/fps/poly_sample_point_evaluate.hpp.html)で$n$において評価する．

#### 制約

- `k + 2 <= mint::getmod()`

#### 計算量

$\pi(k)$を$k$以下の素数の個数とする．

- 時間計算量：$O(k+\pi(k)\log k)$
- 追加の空間計算量：$O(k)$

### `sum_of_polynomial_samples` {#sum-of-polynomial-samples}

#### 宣言

```cpp
template <modint::Modular mint, UnsignedIntegral T>
mint sum_of_polynomial_samples(const std::vector<mint> &samples, T n);
```

#### 概要

次数$k$以下の多項式$f$の値$f(0),f(1),\ldots,f(k)$と非負整数$n$を受け取り，
次の値を返す．

$$
\sum_{i=0}^{n-1}f(i)
$$

#### アルゴリズム

累積和を標本点として，$F(0)=0$および

$$
F(j)=\sum_{i=0}^{j-1}f(i)\quad(1\leq j\leq k+1)
$$

を満たす次数$k+1$以下の多項式$F$を補間する．求める値は$F(n)$なので，
[`sample_point_evaluate`](https://kk2a.github.io/library/fps/poly_sample_point_evaluate.hpp.html)で評価する．
$n\leq k+1$の場合は，入力された標本値を直接加算する．

#### 正当性

$$
H(x)=F(x+1)-F(x)-f(x)
$$

とおく．$H$の次数は高々$k$であり，$j=0,1,\ldots,k$で$H(j)=0$である．したがって$H$は零多項式であり，
$F(x+1)-F(x)=f(x)$が成り立つ．さらに$F(0)=0$なので，すべての非負整数$n$について

$$
F(n)=\sum_{i=0}^{n-1}f(i)
$$

となる．

#### 制約

- `samples`は空でない．
- `samples.size() < mint::getmod()`

#### 計算量

- $n\leq k+1$の場合
  - 時間計算量：$O(n)$
  - 追加の空間計算量：$O(1)$
- $n>k+1$の場合
  - 時間計算量：$O(k)$
  - 追加の空間計算量：$O(k)$

## 等比数列で重み付けした和

### `sum_of_geometric_polynomial_samples`（有限和） {#sum-of-geometric-polynomial-samples-finite}

#### 宣言

```cpp
template <modint::Modular mint, UnsignedIntegral T>
mint sum_of_geometric_polynomial_samples(
    mint r, T n, const std::vector<mint> &samples);
```

#### 概要

次数$k$以下の多項式$f$の標本値$f(0),f(1),\ldots,f(k)$，元$r$，および非負整数$n$を受け取り，

$$
\sum_{i=0}^{n-1}r^if(i)
$$

を返す．

#### アルゴリズム

$r\neq0,1$の場合，次数$k$以下の多項式$T$を

$$
rT(x+1)-T(x)=f(x)
$$

で定めると，$c=-T(0)$として

$$
\sum_{i=0}^{n-1}r^if(i)=c+r^nT(n)
$$

と書ける．$c$は[無限和版](#sum-of-geometric-polynomial-samples-infinite)で計算する．
さらに$T(0)=-c$と

$$
T(i+1)=r^{-1}(T(i)+f(i))
$$

から$T(0),\ldots,T(k)$を求め，[`sample_point_evaluate`](https://kk2a.github.io/library/fps/poly_sample_point_evaluate.hpp.html)で$T(n)$を評価する．
$r=0,1$と$n\leq k+1$の場合は個別に処理する．

#### 正当性

$G(n)=c+r^nT(n)$とおくと，$G(0)=0$であり，

$$
G(n+1)-G(n)=r^n(rT(n+1)-T(n))=r^nf(n)
$$

が成り立つ．したがって$G(n)$と求める有限和は初期値と差分が一致し，両者は等しい．

#### 制約

- `samples`は空でない．
- `samples.size() < mint::getmod()`

#### 計算量

$k=\texttt{samples.size()}-1$とする．

- `r == 0`または$n\leq k+1$の場合：時間$O(n)$，追加の空間$O(1)$
- それ以外の場合：時間$O(k)$，追加の空間$O(k)$

### `sum_of_geometric_polynomial_samples`（無限和） {#sum-of-geometric-polynomial-samples-infinite}

#### 宣言

```cpp
template <modint::Modular mint>
mint sum_of_geometric_polynomial_samples(
    mint r, const std::vector<mint> &samples);
```

#### 概要

次数$k$以下の多項式$f$の標本値$f(0),f(1),\ldots,f(k)$と$r$を受け取り，
形式的冪級数

$$
A(x)=\sum_{i\geq0}r^if(i)x^i
$$

を有理関数とみなしたときの$A(1)$を返す．有限体上での値は，この有理関数を有限体上で評価した値である．

#### アルゴリズム

有限和版の恒等式

$$
\sum_{i=0}^{n-1}r^if(i)=c+r^nT(n)
$$

に現れる$c=-T(0)$を，$A(x)$の分母を$(1-rx)^{k+1}$として計算する．
$(1-rx)^{k+1}A(x)$を次数$k$で打ち切った多項式を$P(x)$とすると，

$$
A(1)=\frac{P(1)}{(1-r)^{k+1}}
$$

である．係数を逐次更新しながら$P(1)$を計算するため，逆元表を用いる．

#### 正当性

$|r|<1$の有理数では，有限和版の恒等式の$n\to\infty$によって$c$が通常の無限和に一致する．
一方，$P(1)/(1-r)^{k+1}$は$r$の有理関数なので，その有理関数を有限体上で評価した値として同じ式を定義できる．

#### 制約

- `samples`は空でない．
- `samples.size() < mint::getmod()`
- `r != 1`

#### 計算量

- 時間計算量：$O(k)$
- 追加の空間計算量：$O(k)$

### `sum_of_geometric_monomial`（有限和） {#sum-of-geometric-monomial-finite}

#### 宣言

```cpp
template <modint::Modular mint, UnsignedIntegral T1, UnsignedIntegral T2>
mint sum_of_geometric_monomial(mint r, T1 n, T2 k);
```

#### 概要

`r`，`n`，`k`を受け取り，次の値を返す．

$$
\sum_{i=0}^{n-1}r^ii^k
$$

#### アルゴリズム

[`pow_table`](https://kk2a.github.io/library/math/multiplicative_function/pow_table.hpp.html)で$0^k,1^k,\ldots,k^k$を列挙し，
[有限和版の`sum_of_geometric_polynomial_samples`](#sum-of-geometric-polynomial-samples-finite)を呼び出す．

#### 制約

- `k + 2 <= mint::getmod()`

#### 計算量

$\pi(k)$を$k$以下の素数の個数とする．

- 時間計算量：$O(k+\pi(k)\log k)$
- 追加の空間計算量：$O(k)$

### `sum_of_geometric_monomial`（無限和） {#sum-of-geometric-monomial-infinite}

#### 宣言

```cpp
template <modint::Modular mint, UnsignedIntegral T>
mint sum_of_geometric_monomial(mint r, T k);
```

#### 概要

`r`と`k`を受け取り，次の値を$r$の有理関数として評価した値を返す．解析的な収束は仮定しない．

$$
\sum_{i=0}^{\infty}r^ii^k
$$

#### アルゴリズム

[`pow_table`](https://kk2a.github.io/library/math/multiplicative_function/pow_table.hpp.html)で$0^k,1^k,\ldots,k^k$を列挙し，
[無限和版の`sum_of_geometric_polynomial_samples`](#sum-of-geometric-polynomial-samples-infinite)を呼び出す．

#### 制約

- `r != 1`
- `k + 2 <= mint::getmod()`

#### 計算量

$\pi(k)$を$k$以下の素数の個数とする．

- 時間計算量：$O(k+\pi(k)\log k)$
- 追加の空間計算量：$O(k)$
