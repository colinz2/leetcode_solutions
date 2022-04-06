
# [小于 K 的两数之和](https://leetcode-cn.com/problems/two-sum-less-than-k)

## 题目描述

<p>给你一个整数数组 <code>nums</code> 和整数 <code>k</code> ，返回最大和 <code>sum</code> ，满足存在 <code>i < j</code> 使得 <code>nums[i] + nums[j] = sum</code> 且 <code>sum < k</code> 。如果没有满足此等式的 <code>i,j</code> 存在，则返回 <code>-1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [34,23,1,24,75,33,54,8], k = 60
<strong>输出：</strong>58
<strong>解释：</strong>
34 和 24 相加得到 58，58 小于 60，满足题意。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [10,20,30], k = 15
<strong>输出：</strong>-1
<strong>解释：</strong>
我们无法找到和小于 15 的两个元素。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 100</code></li>
	<li><code>1 <= nums[i] <= 1000</code></li>
	<li><code>1 <= k <= 2000</code></li>
</ul>


## 题解

### cpp [🔗](two-sum-less-than-k.cpp) 
```cpp
class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int res = -1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int tmp = nums[i] + nums[j];
                if (tmp < k) {
                    res = max(res, tmp);
                }
            }
        }
        return res;
    }
};
```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 
- [双指针](https://leetcode-cn.com/tag/two-pointers) 
- [二分查找](https://leetcode-cn.com/tag/binary-search) 
- [排序](https://leetcode-cn.com/tag/sorting) 


## 相似题目

- [两数之和](../two-sum/README.md)  [Easy] 
- [两数之和 II - 输入有序数组](../two-sum-ii-input-array-is-sorted/README.md)  [Medium] 


## Links

- [Prev](../video-stitching/README.md) 
- [Next](../check-if-a-number-is-majority-element-in-a-sorted-array/README.md) 

