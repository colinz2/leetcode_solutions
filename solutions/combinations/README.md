
# [组合](https://leetcode-cn.com/problems/combinations)

## 题目描述

<p>给定两个整数 <code>n</code> 和 <code>k</code>，返回范围 <code>[1, n]</code> 中所有可能的 <code>k</code> 个数的组合。</p>

<p>你可以按 <strong>任何顺序</strong> 返回答案。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 4, k = 2
<strong>输出：</strong>
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1, k = 1
<strong>输出：</strong>[[1]]</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 20</code></li>
	<li><code>1 <= k <= n</code></li>
</ul>


## 题解

### cpp [🔗](combinations.cpp) 
```cpp
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(res, 1, tmp, n, k);
        return res;
    }

    void backtrack(vector<vector<int>>& res, int index, vector<int> &tmp, int n, int k) {
        if (tmp.size() == k) {
            res.push_back(tmp);
        }
        for (int i = index; i <= n; i++) {
            tmp.push_back(i);
            backtrack(res, i+1, tmp, n, k);
            tmp.pop_back();
        }
    }
};
```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 
- [回溯](https://leetcode-cn.com/tag/backtracking) 


## 相似题目

- [组合总和](../combination-sum/README.md)  [Medium] 
- [全排列](../permutations/README.md)  [Medium] 


## Links

- [Prev](../sort-colors/README.md) 
- [Next](../subsets/README.md) 

