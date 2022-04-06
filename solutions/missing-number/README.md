
# [丢失的数字](https://leetcode-cn.com/problems/missing-number)

## 题目描述

<p>给定一个包含 <code>[0, n]</code>&nbsp;中&nbsp;<code>n</code>&nbsp;个数的数组 <code>nums</code> ，找出 <code>[0, n]</code> 这个范围内没有出现在数组中的那个数。</p>

<ul>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,0,1]
<strong>输出：</strong>2
<b>解释：</b>n = 3，因为有 3 个数字，所以所有的数字都在范围 [0,3] 内。2 是丢失的数字，因为它没有出现在 nums 中。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,1]
<strong>输出：</strong>2
<b>解释：</b>n = 2，因为有 2 个数字，所以所有的数字都在范围 [0,2] 内。2 是丢失的数字，因为它没有出现在 nums 中。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [9,6,4,2,3,5,7,0,1]
<strong>输出：</strong>8
<b>解释：</b>n = 9，因为有 9 个数字，所以所有的数字都在范围 [0,9] 内。8 是丢失的数字，因为它没有出现在 nums 中。</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>nums = [0]
<strong>输出：</strong>1
<b>解释：</b>n = 1，因为有 1 个数字，所以所有的数字都在范围 [0,1] 内。1 是丢失的数字，因为它没有出现在 nums 中。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= n</code></li>
	<li><code>nums</code> 中的所有数字都 <strong>独一无二</strong></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能否实现线性时间复杂度、仅使用额外常数空间的算法解决此问题?</p>


## 题解

### c [🔗](missing-number.c) 
```c
int missingNumber(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++)
        result ^= nums[i]^(i+1);
    return result;
}
```
### cpp [🔗](missing-number.cpp) 
```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        auto sum = std::accumulate(nums.begin(), nums.end(), 0);
        auto size = nums.size();
        return  (size * (size + 1) /2) - sum;
    }
};
```


## 相关话题

- [位运算](https://leetcode-cn.com/tag/bit-manipulation) 
- [数组](https://leetcode-cn.com/tag/array) 
- [哈希表](https://leetcode-cn.com/tag/hash-table) 
- [数学](https://leetcode-cn.com/tag/math) 
- [排序](https://leetcode-cn.com/tag/sorting) 


## 相似题目

- [只出现一次的数字](../single-number/README.md)  [Easy] 


## Links

- [Prev](../palindrome-permutation/README.md) 
- [Next](../closest-binary-search-tree-value/README.md) 

