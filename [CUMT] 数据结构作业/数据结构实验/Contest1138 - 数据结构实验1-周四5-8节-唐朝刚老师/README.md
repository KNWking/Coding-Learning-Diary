# 问题 A: 找新朋友
## 题目描述
新年快到了，天勤准备搞一个聚会，已经知道现有会员 $N$ 人，把会员从 $1$ 到 $N$ 编号，其中会长的号码是 $N$ 号，凡是和会长是老朋友的，那么该会员的号码肯定和 $N$ 有大于 $1$ 的公约数，否则都是新朋友，现在会长想知道究竟有几个新朋友？请你编程序帮会长计算出来。

补充知识：
在数论，对正整数 $n$，欧拉函数 $\phi(N)$ 是小于 $n$ 的正整数中与 $n$ 互质的数的数目.如： $\phi(1) = 1$ 此函数以其首名研究者欧拉命名 (Euler’s totient function)，它又称为 Euler’s totient function、 $\phi$ 函数、欧拉商数等。 例如 $\phi(8) = 4$，因为 $1, 3, 5, 7$ 均和 $8$ 互质。

设： $N = P_1^{q_1} * P_2^{q_2} * … * P_n^{q_n}$.

则： $\phi(N) = N * (1 - \frac{1}{P_1}) * (1 - \frac{1}{P_2}) * … * (1 - \frac{1}{P_n})$

只和底数有关，和指数无关。

如果不利用欧拉函数公式，选择辗转相除法求两个数的最大公约数，在 $oj$ 上无法满足时间要求。

## 输入
第一行是测试数据的组数 $CN$ （Case number， $1 < CN < 10000$），接着有 $CN$ 行正整数 $N$ （ $1 < N < 32768$ ），表示会员人数。

## 输出
对于每一个 $N$，输出一行新朋友的人数，这样共有 $CN$ 行输出。

## 样例输入
```
2
25608
24027

```

## 样例输出
```
7680
16016

```

---
# 问题 B: 互质
## 题目描述
给你一个正整数 $n$，请问有多少个比 $n$ 小的且与 $n$ 互质的正整数？

两个整数互质的意思是，这两个整数没有比 $1$ 大的公约数。

## 输入
输入包含多组测试数据。每组输入是一个正整数 $n$ （ $n \leq 1000000000$ ）。当 $n = 0$ 时，输入结束。

## 输出
对于每组输入，输出比 $n$ 小的且与 $n$ 互质的正整数个数。

## 样例输入
```
7
12
0

```

## 样例输出
```
6
4

```

---
# 问题 C: CPP2023-47-约瑟夫问题
## 题目描述
$n$ 个人围成一圈，按 $1$ 到 $n$ 的顺序编号。从第一个人开始报数（从 $1$ 到 $m$ 报数），凡报到 $m$ 的人退出圈子，问最后留下的是原来的第几号。

## 输入
首先输入两个正整数 $n$ 和 $m$， $n$ 表示 $n$ 个人围一个圈子（ $n \ge 2$ ）， $m$ 表示从 $1$ 报数到 $m$ 的人退出圈子（ $1 \le m$ ）。

## 输出
最后剩下的人的编号。

## 样例输入
```
2 3

```

## 样例输出
```
2

```

---
# 问题 D: CPP2023-25-进制转换
## 题目描述
请编写程序演示把一个 $10$ 进制整数转换为 $R$ 进制的转换结果。

## 输入
正整数 $N$ 和 $R$，空格分隔。

$N$ 是输入的十进制数， $R$ 是需要转换的进制数， $2 \le R \le 20$。

## 输出
将 $10$ 进制整数转换为 $R$ 进制的转换结果，超过 $9$ 的数字符号显示为 $A, B, C, \ldots, Z$ 等字母。

## 样例输入
```
10 16

```

## 样例输出
```
A

```

---
# 问题 E: 整数求和式的计算
## 题目描述
输入两个整数的求和式，比如 $1 + 2 =$ ，输出求和式和对应结果。请编程实现。

## 输入
一个求和式，形如 $a + b =$ 。

## 输出
求和式及对应结果。

## 样例输入
```
1+2=

```

## 样例输出
```
1+2=3

```

---
# 问题 F: 波兰表达式 
## 题目描述
波兰表达式是一种把运算符前置的算术表达式，例如普通的表达式 `2 + 3` 的波兰表示法为 `+ 2 3` 。波兰表达式的优点是运算符之间不必有优先级关系，也不必用括号改变运算次序，例如 `(2 + 3) * 4` 的波兰表示法为 `* + 2 3 4` 。本题求解波兰表达式的值，其中运算符包括 `+` 、`-` 、`*` 、`/` 四个。

## 输入
输入为一行，其中运算符和运算数之间都用空格分隔，运算数是浮点数。

## 输出
输出为一行，表达式的值(保留 $6$ 位小数)。

## 样例输入
```
* + 11.0 12.0 + 24.0 35.0

```

## 样例输出
```
1357.000000

```

---
# 问题 G: 合并队列
## 题目描述
上体育课的时候，老师已经把班级同学排成了两个队列，而且每个队列都是按照从底到高排好队，现在需要把两个队列合并，合并后需要保证还是从低到高排列。合并队列，你能编程实现吗？

## 输入
第 $1$ 行为 $n$ ，表示开始排成的每个队列的长度。第 $2、3$ 行是代表从小到大的 $n$ 个整数，每行的整数间有一个空格间隔。

## 输出
输出占一行，为从小到大的整数，每个整数间间隔一个空格。

## 样例输入
```
5
1 3 5 8 15
2 3 4 6 9

```

## 样例输出
```
1 2 3 3 4 5 6 8 9 15

```
