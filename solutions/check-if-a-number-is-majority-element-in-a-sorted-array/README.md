
# [检查一个数是否在数组中占绝大多数](https://leetcode-cn.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array)

## 题目描述

<p>给出一个按 <strong>非递减</strong> 顺序排列的数组 <code>nums</code>，和一个目标数值 <code>target</code>。假如数组 <code>nums</code> 中绝大多数元素的数值都等于 <code>target</code>，则返回 <code>True</code>，否则请返回 <code>False</code>。</p>

<p>所谓占绝大多数，是指在长度为 <code>N</code> 的数组中出现必须<strong> 超过 <code>N/2</code></strong> <strong>次</strong>。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,4,5,5,5,5,5,6,6], target = 5
<strong>输出：</strong>true
<strong>解释：</strong>
数字 5 出现了 5 次，而数组的长度为 9。
所以，5 在数组中占绝大多数，因为 5 次 > 9/2。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [10,100,101,101], target = 101
<strong>输出：</strong>false
<strong>解释：</strong>
数字 101 出现了 2 次，而数组的长度是 4。
所以，101 <strong>不是 </strong>数组占绝大多数的元素，因为 2 次 = 4/2。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 1000</code></li>
	<li><code>1 <= nums[i] <= 10^9</code></li>
	<li><code>1 <= target <= 10^9</code></li>
</ul>


## 题解

### cpp [🔗](check-if-a-number-is-majority-element-in-a-sorted-array.cpp) 
```cpp
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int cnt = 0;
        for (auto n : nums) {
            if (target == n) cnt++;
            else if (target < n) break;
        }
        return cnt > nums.size()/2;
    }
};
```
### golang [🔗](check-if-a-number-is-majority-element-in-a-sorted-array.go) 
```golang
func isMajorityElement(nums []int, target int) bool {
    j , k := 0, len(nums)
    for j < k {
        m := (j+k)>>1
        if nums[m] < target {
            j = m + 1
        } else {
            k = m
        }
    }
    j += len(nums)/2
    return j < len(nums) && nums[j] == target
}
```
### c [🔗](check-if-a-number-is-majority-element-in-a-sorted-array.c) 
```c
bool isMajorityElement(int* nums, int numsSize, int target){
    int start = 0, end = numsSize-1;
    int targetSize = 0;
    while (start < end) {
        if (nums[start] != target) {
            start++;
        } else if (nums[end] != target) {
            end--;
        }
        if (targetSize == end-start+1) {
            return targetSize > numsSize/2;
        } else {
            targetSize = end-start+1;
        }
    }
    return false;
}
```


## 相关话题

- [数组](../../tags/array.md) 
- [二分查找](../../tags/binary-search.md) 


## 相似题目

- [多数元素](../majority-element/README.md)  [Easy] 


## Links

- [Prev](../two-sum-less-than-k/README.md) 
- [Next](../binary-search-tree-to-greater-sum-tree/README.md) 

