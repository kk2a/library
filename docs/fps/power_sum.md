---
title: Power Sum
documentation_of: //fps/power_sum.hpp
---

形式的冪級数で表された多項式の和を計算する．以下では，長さ$n$の多項式同士を乗算する計算量を$M(n)$と書く．

## 冪和

### `sum_of_monomial_enumerate` {#sum-of-monomial-enumerate}

#### 宣言

```cpp
template <fps::ModularUnivariateFormalPowerSeries FPS,
          UnsignedIntegral T1, UnsignedIntegral T2>
FPS sum_of_monomial_enumerate(T1 n, T2 k);
```

#### 概要

$l=0,\ldots,k$について，次の値を列挙する．返り値の長さは`k + 1`であり，
`result[l]`に対応する値が入る．

$$
\sum_{i=0}^{n-1}i^l
$$

#### アルゴリズム

指数型母関数

$$
\sum_{l\geq 0}\left(\sum_{i=0}^{n-1}i^l\right)\frac{x^l}{l!}
=\sum_{i=0}^{n-1}e^{ix}
=\frac{e^{nx}-1}{e^x-1}
$$

を$x^{k+1}$で打ち切って計算する．分子と分母を$x$で割って定数項を非零にしてから，形式的冪級数除算を行う．

#### 制約

- `k + 1 < FPS::value_type::getmod()`

#### 計算量

- 時間計算量：$O(M(k))$
- 追加の空間計算量：$O(k)$

## 多項式の和

### `sum_of_polynomial` {#sum-of-polynomial}

#### 宣言

```cpp
template <fps::ModularUnivariateFormalPowerSeries FPS,
          modint::Modular mint = typename FPS::value_type, UnsignedIntegral T>
mint sum_of_polynomial(const FPS &f, T n);
```

#### 概要

単項式基底で表した多項式$f(x)=\sum_j f_jx^j$と非負整数$n$を受け取り，次の値を返す．

$$
\sum_{i=0}^{n-1}f(i)
$$

#### アルゴリズム

[`sum_of_monomial_enumerate`](https://kk2a.github.io/library/fps/power_sum.hpp.html#sum-of-monomial-enumerate)で各単項式の和を求め，係数$f_j$との内積を取る．

#### 制約

- `f.size() + 1 < mint::getmod()`

#### 計算量

$d=\deg f$とする．

- 時間計算量：$O(M(d))$
- 追加の空間計算量：$O(d)$

### `prefix_sum_of_polynomial` {#prefix-sum-of-polynomial}

#### 宣言

```cpp
template <fps::ModularUnivariateFormalPowerSeries FPS>
FPS prefix_sum_of_polynomial(const FPS &f);
```

#### 概要

単項式基底で表した多項式$f$を受け取り，すべての非負整数$n$について

$$
g(n)=\sum_{i=0}^{n}f(i)
$$

を満たす多項式$g$を返す．返り値も単項式基底の係数列である．$f$の次数が高々$d$ならば，$g$の次数は高々$d+1$となる．

#### 制約

- `f`は空でない．
- `f.size() < FPS::value_type::getmod()`

#### 計算量

$d=\deg f$とする．

- 時間計算量：$O(M(d))$
- 追加の空間計算量：$O(d)$
