
# [第 N 个泰波那契数](https://leetcode-cn.com/problems/n-th-tribonacci-number)

## 题目描述

<p>泰波那契序列&nbsp;T<sub>n</sub>&nbsp;定义如下：&nbsp;</p>

<p>T<sub>0</sub> = 0, T<sub>1</sub> = 1, T<sub>2</sub> = 1, 且在 n &gt;= 0&nbsp;的条件下 T<sub>n+3</sub> = T<sub>n</sub> + T<sub>n+1</sub> + T<sub>n+2</sub></p>

<p>给你整数&nbsp;<code>n</code>，请返回第 n 个泰波那契数&nbsp;T<sub>n </sub>的值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 4
<strong>输出：</strong>4
<strong>解释：</strong>
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 25
<strong>输出：</strong>1389537
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 37</code></li>
	<li>答案保证是一个 32 位整数，即&nbsp;<code>answer &lt;= 2^31 - 1</code>。</li>
</ul>


## 题解

### cpp [🔗](n-th-tribonacci-number.cpp) 
```cpp
class Solution {
public:
    int tribonacci(int n) {
        int tri[4] = {0,1,};
        for (int i = 1; i <=n; i++) {
            tri[0] = tri[1];
            tri[1] = tri[2];
            tri[2] = tri[3];
            tri[3] = tri[0] + tri[1] + tri[2];
        }
        return tri[3];
    }
};
```


## 相关话题

- [记忆化搜索](../../tags/memoization.md) 
- [数学](../../tags/math.md) 
- [动态规划](../../tags/dynamic-programming.md) 


## 相似题目

- [爬楼梯](../climbing-stairs/README.md)  [Easy] 


## Links

- [Prev](../print-zero-even-odd/README.md) 
- [Next](../decompress-run-length-encoded-list/README.md) 

