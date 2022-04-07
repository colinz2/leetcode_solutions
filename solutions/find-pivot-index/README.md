
# [寻找数组的中心下标](https://leetcode-cn.com/problems/find-pivot-index)

## 题目描述

<p>给你一个整数数组&nbsp;<code>nums</code> ，请计算数组的 <strong>中心下标 </strong>。</p>

<p>数组<strong> 中心下标</strong><strong> </strong>是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。</p>

<p>如果中心下标位于数组最左端，那么左侧数之和视为 <code>0</code> ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。</p>

<p>如果数组有多个中心下标，应该返回 <strong>最靠近左边</strong> 的那一个。如果数组不存在中心下标，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1, 7, 3, 6, 5, 6]
<strong>输出：</strong>3
<strong>解释：</strong>
中心下标是 3 。
左侧数之和 sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11 ，
右侧数之和 sum = nums[4] + nums[5] = 5 + 6 = 11 ，二者相等。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1, 2, 3]
<strong>输出：</strong>-1
<strong>解释：</strong>
数组中不存在满足此条件的中心下标。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [2, 1, -1]
<strong>输出：</strong>0
<strong>解释：</strong>
中心下标是 0 。
左侧数之和 sum = 0 ，（下标 0 左侧不存在元素），
右侧数之和 sum = nums[1] + nums[2] = 1 + -1 = 0 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-1000 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>本题与主站 1991 题相同：<a href="https://leetcode-cn.com/problems/find-the-middle-index-in-array/" target="_blank">https://leetcode-cn.com/problems/find-the-middle-index-in-array/</a></p>


## 题解

### c [🔗](find-pivot-index.c) 
```c
// sum + nums[i] + sum = total
// 2sum = total = num[i]
int pivotIndex(int* nums, int numsSize){
    int total = 0, sum = 0;
    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        if (sum + sum + nums[i] == total) {
            return i;
        }
        sum += nums[i];
    }

    return -1;
}
```
### cpp [🔗](find-pivot-index.cpp) 
```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int lo = 0, l_sum = 0;
        while (lo < nums.size()) {
            if (l_sum == sum - nums[lo]) {
                return lo;
            } else {
                l_sum += nums[lo];
                sum -= nums[lo];
                lo++;
            }
        }
        return -1;
    }
};
```


## 相关话题

- [数组](../../tags/array.md) 
- [前缀和](../../tags/prefix-sum.md) 


## 相似题目

- [和为 K 的子数组](../subarray-sum-equals-k/README.md)  [Medium] 


## Links

- [Prev](../1-bit-and-2-bit-characters/README.md) 
- [Next](../split-linked-list-in-parts/README.md) 

