
# [爬楼梯](https://leetcode-cn.com/problems/climbing-stairs)

## 题目描述

<p>假设你正在爬楼梯。需要 <code>n</code>&nbsp;阶你才能到达楼顶。</p>

<p>每次你可以爬 <code>1</code> 或 <code>2</code> 个台阶。你有多少种不同的方法可以爬到楼顶呢？</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>2
<strong>解释：</strong>有两种方法可以爬到楼顶。
1. 1 阶 + 1 阶
2. 2 阶</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>3
<strong>解释：</strong>有三种方法可以爬到楼顶。
1. 1 阶 + 1 阶 + 1 阶
2. 1 阶 + 2 阶
3. 2 阶 + 1 阶
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 45</code></li>
</ul>


## 题解

### golang [🔗](climbing-stairs.go) 
```golang
func climbStairs(n int) int {
	t := make([]int, n+2)
	t[1] = 1
	t[2] = 2

	for i := 3; i <= n; i++ {
		t[i] = t[i-1] + t[i-2]
	}
	return t[n]
}

```
### cpp [🔗](climbing-stairs.cpp) 
```cpp
class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) return n;
        vector<int> dp(n+1);
        dp[1] = 1, dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
```


## 相关话题

- [记忆化搜索](../../tags/memoization.md) 
- [数学](../../tags/math.md) 
- [动态规划](../../tags/dynamic-programming.md) 


## 相似题目

- [斐波那契数](../fibonacci-number/README.md)  [Easy] 
- [第 N 个泰波那契数](../n-th-tribonacci-number/README.md)  [Easy] 


## Links

- [Prev](../sqrtx/README.md) 
- [Next](../simplify-path/README.md) 

