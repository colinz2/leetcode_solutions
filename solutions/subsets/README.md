
# [子集](https://leetcode-cn.com/problems/subsets)

## 题目描述

<p>给你一个整数数组 <code>nums</code> ，数组中的元素 <strong>互不相同</strong> 。返回该数组所有可能的子集（幂集）。</p>

<p>解集 <strong>不能</strong> 包含重复的子集。你可以按 <strong>任意顺序</strong> 返回解集。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
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
	<li><code>nums</code> 中的所有元素 <strong>互不相同</strong></li>
</ul>


## 题解

### cpp [🔗](subsets.cpp) 
```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> one;
        FindSubsets(nums, 0, one, res);
        return res;
    }

private:
    void FindSubsets(vector<int>& nums, int index, vector<int>& one, vector<vector<int>>& res) {
        res.push_back(one);
        for (int i = index; i < nums.size(); i++) {
            one.push_back(nums[i]);
            FindSubsets(nums, i + 1, one, res);
            one.pop_back();
        }
    }
};
```


## 相关话题

- [位运算](https://leetcode-cn.com/tag/bit-manipulation) 
- [数组](https://leetcode-cn.com/tag/array) 
- [回溯](https://leetcode-cn.com/tag/backtracking) 


## 相似题目

- [子集 II](../subsets-ii/README.md)  [Medium] 
- [字母大小写全排列](../letter-case-permutation/README.md)  [Medium] 


## Links

- [Prev](../combinations/README.md) 
- [Next](../word-search/README.md) 

