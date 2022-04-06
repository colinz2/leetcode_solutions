
# [有序数组中的单一元素](https://leetcode-cn.com/problems/single-element-in-a-sorted-array)

## 题目描述

<p>给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。</p>

<p>请你找出并返回只出现一次的那个数。</p>

<p>你设计的解决方案必须满足 <code>O(log n)</code> 时间复杂度和 <code>O(1)</code> 空间复杂度。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,1,2,3,3,4,4,8,8]
<strong>输出:</strong> 2
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums =  [3,3,7,7,10,11,11]
<strong>输出:</strong> 10
</pre>

<p>&nbsp;</p>

<p><meta charset="UTF-8" /></p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i]&nbsp;&lt;= 10<sup>5</sup></code></li>
</ul>


## 题解

### cpp [🔗](single-element-in-a-sorted-array.cpp) 
```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            if (mid % 2) mid--;
            if (nums[mid] == nums[mid + 1]) {
                lo += 2;
            } else {
                hi = mid;
            }
        }
        return nums[hi];
    }
};
```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 
- [二分查找](https://leetcode-cn.com/tag/binary-search) 


## 相似题目



## Links

- [Prev](../convert-bst-to-greater-tree/README.md) 
- [Next](../reverse-string-ii/README.md) 

