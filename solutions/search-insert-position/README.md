
# [搜索插入位置](https://leetcode-cn.com/problems/search-insert-position)

## 题目描述

<p>给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。</p>

<p>请必须使用时间复杂度为 <code>O(log n)</code> 的算法。</p>

<p> </p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,3,5,6], target = 5
<strong>输出:</strong> 2
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,3,5,6], target = 2
<strong>输出:</strong> 1
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,3,5,6], target = 7
<strong>输出:</strong> 4
</pre>

<p><strong>示例 4:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,3,5,6], target = 0
<strong>输出:</strong> 0
</pre>

<p><strong>示例 5:</strong></p>

<pre>
<strong>输入:</strong> nums = [1], target = 0
<strong>输出:</strong> 0
</pre>

<p> </p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> <= nums[i] <= 10<sup>4</sup></code></li>
	<li><code>nums</code> 为<strong>无重复元素</strong>的<strong>升序</strong>排列数组</li>
	<li><code>-10<sup>4</sup> <= target <= 10<sup>4</sup></code></li>
</ul>


## 题解

### cpp [🔗](search-insert-position.cpp) 
```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int mid = 0;
        while (l <= r) {
            mid = l + (r - l)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 
- [二分查找](https://leetcode-cn.com/tag/binary-search) 


## 相似题目

- [第一个错误的版本](../first-bad-version/README.md)  [Easy] 


## Links

- [Prev](../string-to-integer-atoi/README.md) 
- [Next](../binary-tree-level-order-traversal/README.md) 

