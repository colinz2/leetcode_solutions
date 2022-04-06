
# [连续的子数组和](https://leetcode-cn.com/problems/continuous-subarray-sum)

## 题目描述

<p>给你一个整数数组 <code>nums</code> 和一个整数 <code>k</code> ，编写一个函数来判断该数组是否含有同时满足下述条件的连续子数组：</p>

<ul>
	<li>子数组大小 <strong>至少为 2</strong> ，且</li>
	<li>子数组元素总和为 <code>k</code> 的倍数。</li>
</ul>

<p>如果存在，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>如果存在一个整数 <code>n</code> ，令整数 <code>x</code> 符合 <code>x = n * k</code> ，则称 <code>x</code> 是 <code>k</code> 的一个倍数。<code>0</code> 始终视为 <code>k</code> 的一个倍数。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [23<u>,2,4</u>,6,7], k = 6
<strong>输出：</strong>true
<strong>解释：</strong>[2,4] 是一个大小为 2 的子数组，并且和为 6 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [<u>23,2,6,4,7</u>], k = 6
<strong>输出：</strong>true
<strong>解释：</strong>[23, 2, 6, 4, 7] 是大小为 5 的子数组，并且和为 42 。 
42 是 6 的倍数，因为 42 = 7 * 6 且 7 是一个整数。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [23,2,6,4,7], k = 13
<strong>输出：</strong>false
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>0 <= nums[i] <= 10<sup>9</sup></code></li>
	<li><code>0 <= sum(nums[i]) <= 2<sup>31</sup> - 1</code></li>
	<li><code>1 <= k <= 2<sup>31</sup> - 1</code></li>
</ul>


## 题解

### cpp [🔗](continuous-subarray-sum.cpp) 
```cpp
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m{{0,-1}};
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int t = sum % k;
            auto it = m.find(t);
            if (it != m.end()) {
                if (i - it->second > 1) return true;
            } else{
                m[t] = i;
            }
        }
        return false;
    }
};
```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 
- [哈希表](https://leetcode-cn.com/tag/hash-table) 
- [数学](https://leetcode-cn.com/tag/math) 
- [前缀和](https://leetcode-cn.com/tag/prefix-sum) 


## 相似题目

- [和为 K 的子数组](../subarray-sum-equals-k/README.md)  [Medium] 


## Links

- [Prev](../detect-capital/README.md) 
- [Next](../encode-and-decode-tinyurl/README.md) 

