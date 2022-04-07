
# [子集 II](https://leetcode-cn.com/problems/subsets-ii)

## 题目描述

<p>给你一个整数数组 <code>nums</code> ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。</p>

<p>解集 <strong>不能</strong> 包含重复的子集。返回的解集中，子集可以按 <strong>任意顺序</strong> 排列。</p>

<div class="original__bRMd">
<div>
<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,2]
<strong>输出：</strong>[[],[1],[1,2],[1,2,2],[2],[2,2]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0]
<strong>输出：</strong>[[],[0]]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10</code></li>
	<li><code>-10 <= nums[i] <= 10</code></li>
</ul>
</div>
</div>


## 题解

### cpp [🔗](subsets-ii.cpp) 
```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        std::sort(nums.begin(), nums.end());
        backtrace(res, 0, nums, tmp);
        return res;          
    }

    void backtrace(vector<vector<int>>& res, int index, vector<int>& nums, vector<int>& tmp) {
        res.push_back(tmp);
        for (int i = index; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            backtrace(res, i+1, nums, tmp);
            tmp.pop_back();
            while (i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        }
    }
};
```


## 相关话题

- [位运算](https://leetcode-cn.com/tag/bit-manipulation) 
- [数组](https://leetcode-cn.com/tag/array) 
- [回溯](https://leetcode-cn.com/tag/backtracking) 


## 相似题目

- [子集](../subsets/README.md)  [Medium] 


## Links

- [Prev](../gray-code/README.md) 
- [Next](../reverse-linked-list-ii/README.md) 

