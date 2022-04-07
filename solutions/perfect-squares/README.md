
# [完全平方数](https://leetcode-cn.com/problems/perfect-squares)

## 题目描述

<p>给你一个整数 <code>n</code> ，返回 <em>和为 <code>n</code> 的完全平方数的最少数量</em> 。</p>

<p><strong>完全平方数</strong> 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，<code>1</code>、<code>4</code>、<code>9</code> 和 <code>16</code> 都是完全平方数，而 <code>3</code> 和 <code>11</code> 不是。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>n = <code>12</code>
<strong>输出：</strong>3 
<strong>解释：</strong><code>12 = 4 + 4 + 4</code></pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = <code>13</code>
<strong>输出：</strong>2
<strong>解释：</strong><code>13 = 4 + 9</code></pre>
&nbsp;

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
</ul>


## 题解

### cpp [🔗](perfect-squares.cpp) 
```cpp
class Solution {

public:
    int numSquares(int n) {

        vector<int> mem(n + 1, -1);

        return numSquares(n, mem);
    }

private:
    int numSquares(int n, vector<int>& mem){

        if(n == 0)
            return 0;

        if(mem[n] != -1)
            return mem[n];

        int res = INT_MAX;
        for(int i = 1; n - i * i >= 0; i ++ )
            res = min(res, 1 + numSquares(n - i * i, mem));
        return mem[n] = res;
    }
};
```


## 相关话题

- [广度优先搜索](../../tags/breadth-first-search.md) 
- [数学](../../tags/math.md) 
- [动态规划](../../tags/dynamic-programming.md) 


## 相似题目

- [计数质数](../count-primes/README.md)  [Medium] 
- [丑数 II](../ugly-number-ii/README.md)  [Medium] 


## Links

- [Prev](../first-bad-version/README.md) 
- [Next](../move-zeroes/README.md) 

