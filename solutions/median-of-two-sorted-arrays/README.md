
# [寻找两个正序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays)

## 题目描述

<p>给定两个大小分别为 <code>m</code> 和 <code>n</code> 的正序（从小到大）数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>。请你找出并返回这两个正序数组的 <strong>中位数</strong> 。</p>

<p>算法的时间复杂度应该为 <code>O(log (m+n))</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1,3], nums2 = [2]
<strong>输出：</strong>2.00000
<strong>解释：</strong>合并数组 = [1,2,3] ，中位数 2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1,2], nums2 = [3,4]
<strong>输出：</strong>2.50000
<strong>解释：</strong>合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
</pre>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>nums1.length == m</code></li>
	<li><code>nums2.length == n</code></li>
	<li><code>0 &lt;= m &lt;= 1000</code></li>
	<li><code>0 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= m + n &lt;= 2000</code></li>
	<li><code>-10<sup>6</sup> &lt;= nums1[i], nums2[i] &lt;= 10<sup>6</sup></code></li>
</ul>


## 题解

### cpp [🔗](median-of-two-sorted-arrays.cpp) 
```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (auto n1 : nums1) {
            nums2.push_back(n1);
        }
        sort(nums2.begin(), nums2.end());
        if (nums2.size() % 2) {
            return nums2[nums2.size() / 2];
        }

        return (nums2[nums2.size() / 2] + nums2[nums2.size() / 2 - 1]) / 2.0;
    }
};
```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 
- [二分查找](https://leetcode-cn.com/tag/binary-search) 
- [分治](https://leetcode-cn.com/tag/divide-and-conquer) 


## 相似题目



## Links

- [Prev](../longest-substring-without-repeating-characters/README.md) 
- [Next](../longest-palindromic-substring/README.md) 

