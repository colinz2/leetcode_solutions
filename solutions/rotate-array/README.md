
# [轮转数组](https://leetcode-cn.com/problems/rotate-array)

## 题目描述

<p>给你一个数组，将数组中的元素向右轮转 <code>k</code><em>&nbsp;</em>个位置，其中&nbsp;<code>k</code><em>&nbsp;</em>是非负数。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,2,3,4,5,6,7], k = 3
<strong>输出:</strong> <code>[5,6,7,1,2,3,4]</code>
<strong>解释:</strong>
向右轮转 1 步: <code>[7,1,2,3,4,5,6]</code>
向右轮转 2 步: <code>[6,7,1,2,3,4,5]
</code>向右轮转 3 步: <code>[5,6,7,1,2,3,4]</code>
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,-100,3,99], k = 2
<strong>输出：</strong>[3,99,-1,-100]
<strong>解释:</strong> 
向右轮转 1 步: [99,-1,-100,3]
向右轮转 2 步: [3,99,-1,-100]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>尽可能想出更多的解决方案，至少有 <strong>三种</strong> 不同的方法可以解决这个问题。</li>
	<li>你可以使用空间复杂度为&nbsp;<code>O(1)</code> 的&nbsp;<strong>原地&nbsp;</strong>算法解决这个问题吗？</li>
</ul>

<ul>
</ul>

<ul>
</ul>


## 题解

### cpp [🔗](rotate-array.cpp) 
```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto size = nums.size();
        if (size == 1) {
            return ;
        }
        for (auto i = 0; i < k; i++) {
            auto f = nums[0];
            auto e = nums[size - 1];
            for (auto j = size - 1; j > 1; j--) {
                nums[j] = nums[j - 1]; 
            }
            nums[1] = f;
            nums[0] = e;
            //auto new_index = (i + k) % size;
        }
    }
};
```


## 相关话题

- [数组](../../tags/array.md) 
- [数学](../../tags/math.md) 
- [双指针](../../tags/two-pointers.md) 


## 相似题目

- [旋转链表](../rotate-list/README.md)  [Medium] 


## Links

- [Prev](../largest-number/README.md) 
- [Next](../reverse-bits/README.md) 

