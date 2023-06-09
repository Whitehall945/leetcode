# 96 不同的二叉搜索树(m)

设两个函数：

$G(n)$：长度为$n$的序列构成的不同BST个数，易得$G(0) =G(1)=1$ 

$F(i,n)$：长度为$n$的以$i$为根节点的不同的BST个数

两者的关系是
$$
G(n) = \sum_1^n F(i,n)
$$
以$i$为根节点的所有BST的数量
$$
1\quad 2 \quad 3 \quad ... \quad i-1 \quad i \quad i+1 \quad ... \quad n
$$
是
$$
G(i-1)*G(n-i)
$$
也就是$F(i,n)$，于是有
$$
G(n) = \sum_1^n G(i-1)*G(n-i)
$$
对应的代码为

```c++
for (int i = 2; i <= n; i++) {
	for (int j = 1; j <= i; j++) {
		dp[i] += dp[j - 1] * dp[i - j];
	}
}
```

