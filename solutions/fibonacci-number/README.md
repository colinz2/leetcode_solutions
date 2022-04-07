
# [斐波那契数](https://leetcode-cn.com/problems/fibonacci-number)

## 题目描述

<p><strong>斐波那契数</strong>&nbsp;（通常用&nbsp;<code>F(n)</code> 表示）形成的序列称为 <strong>斐波那契数列</strong> 。该数列由&nbsp;<code>0</code> 和 <code>1</code> 开始，后面的每一项数字都是前面两项数字的和。也就是：</p>

<pre>
F(0) = 0，F(1)&nbsp;= 1
F(n) = F(n - 1) + F(n - 2)，其中 n &gt; 1
</pre>

<p>给定&nbsp;<code>n</code> ，请计算 <code>F(n)</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>1
<strong>解释：</strong>F(2) = F(1) + F(0) = 1 + 0 = 1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>2
<strong>解释：</strong>F(3) = F(2) + F(1) = 1 + 1 = 2
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 4
<strong>输出：</strong>3
<strong>解释：</strong>F(4) = F(3) + F(2) = 2 + 1 = 3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 30</code></li>
</ul>


## 题解

### c [🔗](fibonacci-number.c) 
```c
int fib(int n) {
    int fibs[2] = {0, 1, };
    while (n > 1) {
        fibs[0] = fibs[0] + fibs[1];
        fibs[1] = fibs[0] + fibs[1];
        n -= 2;
    }
    return fibs[n]; 
}
```
### python3 [🔗](fibonacci-number.py) 
```python3
class Solution:
    def fib(self, n: int) -> int:
        return int((5**0.5)*0.2*( ((1+5**0.5)/2)**n-((1-5**0.5)/2)**n))
```
### golang [🔗](fibonacci-number.go) 
```golang
func fib(n int) int {
    if n < 2 {
        return n
    }
    return fib(n-1) + fib(n-2)
}
```
### cpp [🔗](fibonacci-number.cpp) 
```cpp
class Solution {
public:
    int fib(int n) {
        int fb[3] = {0, 1};
        for (int i = 1; i <= n; i++) {
            fb[0] = fb[1];
            fb[1] = fb[2];
            fb[2] = fb[0] + fb[1];
        }
        return fb[2];
    }
};
```


## 相关话题

- [递归](../../tags/recursion.md) 
- [记忆化搜索](../../tags/memoization.md) 
- [数学](../../tags/math.md) 
- [动态规划](../../tags/dynamic-programming.md) 


## 相似题目

- [爬楼梯](../climbing-stairs/README.md)  [Easy] 


## Links

- [Prev](../univalued-binary-tree/README.md) 
- [Next](../fixed-point/README.md) 

