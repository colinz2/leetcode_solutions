
# [最长连续序列](https://leetcode-cn.com/problems/longest-consecutive-sequence)

## 题目描述

<p>给定一个未排序的整数数组 <code>nums</code> ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。</p>

<p>请你设计并实现时间复杂度为 <code>O(n)</code><em> </em>的算法解决此问题。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [100,4,200,1,3,2]
<strong>输出：</strong>4
<strong>解释：</strong>最长数字连续序列是 <code>[1, 2, 3, 4]。它的长度为 4。</code></pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,3,7,2,5,8,4,6,0,1]
<strong>输出：</strong>9
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> <= nums[i] <= 10<sup>9</sup></code></li>
</ul>


## 题解

### cpp [🔗](longest-consecutive-sequence.cpp) 
```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set;
        int max_len = 0;
        for (auto &n : nums) {
            nums_set.insert(n);
        }

        for (auto &n : nums) {
            // 从起点开始
            if (nums_set.count(n-1) == 0) {
                int next = n;
                while(nums_set.count(next)) {
                    next++;
                }
                max_len = std::max(max_len, next - n);
            }
        }

        return max_len;
    }
};
```


## 相关话题

- [并查集](https://leetcode-cn.com/tag/union-find) 
- [数组](https://leetcode-cn.com/tag/array) 
- [哈希表](https://leetcode-cn.com/tag/hash-table) 


## 相似题目



## Links

- [Prev](../valid-palindrome/README.md) 
- [Next](../sum-root-to-leaf-numbers/README.md) 

