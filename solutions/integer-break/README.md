
# [整数拆分](https://leetcode-cn.com/problems/integer-break)

## 题目描述

<p>给定一个正整数&nbsp;<code>n</code>&nbsp;，将其拆分为 <code>k</code> 个 <strong>正整数</strong> 的和（&nbsp;<code>k &gt;= 2</code>&nbsp;），并使这些整数的乘积最大化。</p>

<p>返回 <em>你可以获得的最大乘积</em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入: </strong>n = 2
<strong>输出: </strong>1
<strong>解释: </strong>2 = 1 + 1, 1 × 1 = 1。</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入: </strong>n = 10
<strong>输出: </strong>36
<strong>解释: </strong>10 = 3 + 3 + 4, 3 ×&nbsp;3 ×&nbsp;4 = 36。</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 58</code></li>
</ul>


## 题解

### cpp [🔗](integer-break.cpp) 
```cpp
class Solution {
public:
    int integerBreak(int n) {
        vector<int>memo(n + 1, 1);
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                int max_tmp = max(j * (i - j), j * memo[i - j]);
                memo[i] = max(memo[i], max_tmp);
            }
        }
        return memo[n];
    }
};
```


## 相关话题

- [数学](../../tags/math.md) 
- [动态规划](../../tags/dynamic-programming.md) 


## 相似题目



## Links

- [Prev](../counting-bits/README.md) 
- [Next](../reverse-string/README.md) 

