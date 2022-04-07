
# [和为 K 的子数组](https://leetcode-cn.com/problems/subarray-sum-equals-k)

## 题目描述

<p>给你一个整数数组 <code>nums</code> 和一个整数&nbsp;<code>k</code> ，请你统计并返回 <em>该数组中和为&nbsp;<code>k</code><strong>&nbsp;</strong>的子数组的个数&nbsp;</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1], k = 2
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3], k = 3
<strong>输出：</strong>2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>-1000 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>-10<sup>7</sup> &lt;= k &lt;= 10<sup>7</sup></code></li>
</ul>


## 题解

### cpp [🔗](subarray-sum-equals-k.cpp) 
```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map{{0, 1}};
        int res = 0, sum = 0;
        for (auto num : nums) {
            sum += num;
            auto it = map.find(sum - k);
            if (it != map.end()) {
                res += it->second;
            }
            ++map[sum];
        }
        return res;   
    }
};
```


## 相关话题

- [数组](../../tags/array.md) 
- [哈希表](../../tags/hash-table.md) 
- [前缀和](../../tags/prefix-sum.md) 


## 相似题目

- [两数之和](../two-sum/README.md)  [Easy] 
- [连续的子数组和](../continuous-subarray-sum/README.md)  [Medium] 
- [寻找数组的中心下标](../find-pivot-index/README.md)  [Easy] 


## Links

- [Prev](../reverse-words-in-a-string-iii/README.md) 
- [Next](../distribute-candies/README.md) 

