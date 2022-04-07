
# [因子的组合](https://leetcode-cn.com/problems/factor-combinations)

## 题目描述

<p>整数可以被看作是其因子的乘积。</p>

<p>例如：</p>

<pre>8 = 2 x 2 x 2;
  = 2 x 4.</pre>

<p>请实现一个函数，该函数接收一个整数 <em>n</em>&nbsp;并返回该整数所有的因子组合。</p>

<p><strong>注意：</strong></p>

<ol>
	<li>你可以假定 <em>n</em> 为永远为正数。</li>
	<li>因子必须大于 1 并且小于 <em>n</em>。</li>
</ol>

<p><strong>示例 1：</strong></p>

<pre><strong>输入: </strong><code>1</code>
<strong>输出: </strong>[]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入: </strong><code>37</code>
<strong>输出: </strong>[]</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入: </strong><code>12</code>
<strong>输出:</strong>
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]</pre>

<p><strong>示例 4: </strong></p>

<pre><strong>输入: </strong><code>32</code>
<strong>输出:</strong>
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
</pre>


## 题解

### cpp [🔗](factor-combinations.cpp) 
```cpp
class Solution {
public:
    vector<vector<int>> getFactors(int n) {

        function<vector<vector<int>>(int, int)> dfs = [&](int n, int start) {
            vector<vector<int>> res;
            for (int i = start; i*i <= n; i++) {
                if (n % i == 0) {
                    res.push_back({i, n / i});
                    for (auto &v : dfs(n / i, i)) {
                        v.push_back(i);
                        res.push_back(v);
                    }
                }
            }
            return res;
        };

        return dfs(n, 2);
    }
};
```


## 相关话题

- [数组](../../tags/array.md) 
- [回溯](../../tags/backtracking.md) 


## 相似题目

- [组合总和](../combination-sum/README.md)  [Medium] 


## Links

- [Prev](../meeting-rooms/README.md) 
- [Next](../binary-tree-paths/README.md) 

