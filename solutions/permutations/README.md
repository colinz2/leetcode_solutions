
# [全排列](https://leetcode-cn.com/problems/permutations)

## 题目描述

<p>给定一个不含重复数字的数组 <code>nums</code> ，返回其 <em>所有可能的全排列</em> 。你可以 <strong>按任意顺序</strong> 返回答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,1]
<strong>输出：</strong>[[0,1],[1,0]]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1]
<strong>输出：</strong>[[1]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 6</code></li>
	<li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
	<li><code>nums</code> 中的所有整数 <strong>互不相同</strong></li>
</ul>


## 题解

### python3 [🔗](permutations.py) 
```python3
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        def backtrack(nums, tmp):
            if not nums:
                res.append(tmp)
                return 
            for i in range(len(nums)):
                backtrack(nums[:i] + nums[i+1:], tmp + [nums[i]])
                
        backtrack(nums, [])
        return res

```
### cpp [🔗](permutations.cpp) 
```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<bool> vis;
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        vis.resize(nums.size());

        vector<int> tmp;
        backtrack(nums, tmp, 0);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& tmp, int index) {
        if (index == nums.size()) {
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!vis[i]) {
                vis[i] = true;
                tmp.push_back(nums[i]);
                backtrack(nums, tmp, index+1);
                tmp.pop_back();
                vis[i] = false;
            }
        }
    }
};
```


## 相关话题

- [数组](../../tags/array.md) 
- [回溯](../../tags/backtracking.md) 


## 相似题目

- [组合](../combinations/README.md)  [Medium] 


## Links

- [Prev](../wildcard-matching/README.md) 
- [Next](../rotate-image/README.md) 

