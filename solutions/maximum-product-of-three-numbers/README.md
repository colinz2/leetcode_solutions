
# [三个数的最大乘积](https://leetcode-cn.com/problems/maximum-product-of-three-numbers)

## 题目描述

<p>给你一个整型数组 <code>nums</code> ，在数组中找出由三个数组成的最大乘积，并输出这个乘积。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>6
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4]
<strong>输出：</strong>24
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,-2,-3]
<strong>输出：</strong>-6
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 <= nums.length <= 10<sup>4</sup></code></li>
	<li><code>-1000 <= nums[i] <= 1000</code></li>
</ul>


## 题解

### cpp [🔗](maximum-product-of-three-numbers.cpp) 
```cpp
class Solution {
public:
    int maximumProduct(vector<int>& nums) {        
        if (nums.size() < 3) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int a = nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
        int b = nums[nums.size() - 1]* nums[0] * nums[1];
        return a > b ? a : b;
    }
};
```


## 相关话题

- [数组](../../tags/array.md) 
- [数学](../../tags/math.md) 
- [排序](../../tags/sorting.md) 


## 相似题目



## Links

- [Prev](../merge-two-binary-trees/README.md) 
- [Next](../sum-of-square-numbers/README.md) 

