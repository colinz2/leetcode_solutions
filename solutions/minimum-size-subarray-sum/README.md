
# [长度最小的子数组](https://leetcode-cn.com/problems/minimum-size-subarray-sum)

## 题目描述

<p>给定一个含有 <code>n</code><strong> </strong>个正整数的数组和一个正整数 <code>target</code><strong> 。</strong></p>

<p>找出该数组中满足其和<strong> </strong><code>≥ target</code><strong> </strong>的长度最小的 <strong>连续子数组</strong> <code>[nums<sub>l</sub>, nums<sub>l+1</sub>, ..., nums<sub>r-1</sub>, nums<sub>r</sub>]</code> ，并返回其长度<strong>。</strong>如果不存在符合条件的子数组，返回 <code>0</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>target = 7, nums = [2,3,1,2,4,3]
<strong>输出：</strong>2
<strong>解释：</strong>子数组 <code>[4,3]</code> 是该条件下的长度最小的子数组。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>target = 4, nums = [1,4,4]
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>target = 11, nums = [1,1,1,1,1,1,1,1]
<strong>输出：</strong>0
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= target <= 10<sup>9</sup></code></li>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= nums[i] <= 10<sup>5</sup></code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong></p>

<ul>
	<li>如果你已经实现<em> </em><code>O(n)</code> 时间复杂度的解法, 请尝试设计一个 <code>O(n log(n))</code> 时间复杂度的解法。</li>
</ul>


## 题解

### cpp [🔗](minimum-size-subarray-sum.cpp) 
```cpp
class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int l = 0, r = -1;
        int sum = 0;
        int ret = nums.size() + 1;

        while (l < nums.size()) {
            if (r + 1 < nums.size() && sum < s) {
                sum += nums[++r];
            } else {
                sum -= nums[l++];
            }

            if (sum >= s) {
                ret = std::min(ret, r-l+1);
            }
        }
        if (ret > nums.size()) ret = 0;
        return ret;
    }
};

```


## 相关话题

- [数组](../../tags/array.md) 
- [二分查找](../../tags/binary-search.md) 
- [前缀和](../../tags/prefix-sum.md) 
- [滑动窗口](../../tags/sliding-window.md) 


## 相似题目



## Links

- [Prev](../implement-trie-prefix-tree/README.md) 
- [Next](../design-add-and-search-words-data-structure/README.md) 

