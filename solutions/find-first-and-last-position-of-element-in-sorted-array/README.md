
# [在排序数组中查找元素的第一个和最后一个位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array)

## 题目描述

<p>给定一个按照升序排列的整数数组 <code>nums</code>，和一个目标值 <code>target</code>。找出给定目标值在数组中的开始位置和结束位置。</p>

<p>如果数组中不存在目标值 <code>target</code>，返回 <code>[-1, -1]</code>。</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>你可以设计并实现时间复杂度为 <code>O(log n)</code> 的算法解决此问题吗？</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [<code>5,7,7,8,8,10]</code>, target = 8
<strong>输出：</strong>[3,4]</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [<code>5,7,7,8,8,10]</code>, target = 6
<strong>输出：</strong>[-1,-1]</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [], target = 0
<strong>输出：</strong>[-1,-1]</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> <= nums[i] <= 10<sup>9</sup></code></li>
	<li><code>nums</code> 是一个非递减数组</li>
	<li><code>-10<sup>9</sup> <= target <= 10<sup>9</sup></code></li>
</ul>


## 题解

### cpp [🔗](find-first-and-last-position-of-element-in-sorted-array.cpp) 
```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lower_bound = [&]() ->int {
            int j = 0, k = nums.size();
            while (j < k) {
                int m = j + (k -j)/2;
                if (nums[m] < target) {
                    j = m + 1;
                } else {
                    k = m;
                }
            }
            return j;
        };

        auto upper_bound = [&]() -> int {
            int j = 0, k = nums.size();
            while (j < k) {
                int m = j + (k-j)/2;
                if (nums[m] <= target) {
                    j = m + 1;
                } else {
                    k = m;
                }
            }
            return j;
        };

        int j = lower_bound(), 
            k = upper_bound();
        if (j == k) {
            return {-1, -1};
        }

        return {j, k-1};
    }
};
```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 
- [二分查找](https://leetcode-cn.com/tag/binary-search) 


## 相似题目

- [第一个错误的版本](../first-bad-version/README.md)  [Easy] 


## Links

- [Prev](../search-in-rotated-sorted-array/README.md) 
- [Next](../search-insert-position/README.md) 

