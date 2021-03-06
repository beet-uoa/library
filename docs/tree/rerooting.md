---
title: ReRooting
documentation_of: //tree/rerooting.cpp
---

## できること
全ての頂点について、その頂点を根としたときの木DPの結果を求める

ある頂点を根としたときの部分木の結果を求めることもできる [問題](https://atcoder.jp/contests/tenka1-2015-quala/tasks/tenka1_2015_qualA_d) [提出例](https://atcoder.jp/contests/tenka1-2015-quala/submissions/11218391)

## データの持ち方
- `T`: 結果
- `Edge`: 辺の情報
- `Node`: 逆辺のindexなどを管理する

## つかいかた
以下のラムダ式を実装する
- `fold(x, y)`: 結果 `x` と結果 `y` をマージ
- `lift(x, e)`: 結果 `x` を辺 `e` を使って上に持ち上げる

## 計算量
頂点数を $N$ として $O(N \log N)$

「ある頂点を根としたときの部分木の結果」が必要なければ $O(N)$ にもできる

## 参考リンク
[†全方位木DP†について](https://ei1333.hateblo.jp/entry/2017/04/10/224413)

[もうひとつの全方位木DP](https://ei1333.hateblo.jp/entry/2018/12/21/004022)
