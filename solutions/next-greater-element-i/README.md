
# [下一个更大元素 I](https://leetcode-cn.com/problems/next-greater-element-i)

## 题目描述

<p>给你两个<strong> 没有重复元素</strong> 的数组 <code>nums1</code> 和 <code>nums2</code> ，其中<code>nums1</code> 是 <code>nums2</code> 的子集。</p>

<p>请你找出 <code>nums1</code> 中每个元素在 <code>nums2</code> 中的下一个比其大的值。</p>

<p><code>nums1</code> 中数字 <code>x</code> 的下一个更大元素是指 <code>x</code> 在 <code>nums2</code> 中对应位置的右边的第一个比 <code>x</code><strong> </strong>大的元素。如果不存在，对应位置输出 <code>-1</code> 。</p>

<p> </p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums1 = [4,1,2], nums2 = [1,3,4,2].
<strong>输出:</strong> [-1,3,-1]
<strong>解释:</strong>
    对于 num1 中的数字 4 ，你无法在第二个数组中找到下一个更大的数字，因此输出 -1 。
    对于 num1 中的数字 1 ，第二个数组中数字1右边的下一个较大数字是 3 。
    对于 num1 中的数字 2 ，第二个数组中没有下一个更大的数字，因此输出 -1 。</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums1 = [2,4], nums2 = [1,2,3,4].
<strong>输出:</strong> [3,-1]
<strong>解释:</strong>
    对于 num1 中的数字 2 ，第二个数组中的下一个较大数字是 3 。
    对于 num1 中的数字 4 ，第二个数组中没有下一个更大的数字，因此输出 -1 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums1.length <= nums2.length <= 1000</code></li>
	<li><code>0 <= nums1[i], nums2[i] <= 10<sup>4</sup></code></li>
	<li><code>nums1</code>和<code>nums2</code>中所有整数 <strong>互不相同</strong></li>
	<li><code>nums1</code> 中的所有整数同样出现在 <code>nums2</code> 中</li>
</ul>

<p> </p>

<p><strong>进阶：</strong>你可以设计一个时间复杂度为 <code>O(nums1.length + nums2.length)</code> 的解决方案吗？</p>


## 题解

### cpp [🔗](next-greater-element-i.cpp) 
```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        stack<int> st;
        map<int, int> m;
        // 先遍历 nums2 啊，再遍历 nums1，类似每日温度
        for (auto &v : nums2) {
            m[v] = -1;
            while (!st.empty() && v > st.top()) {
                m[st.top()] = v;
                st.pop();
            }
            st.push(v);
        }

        for (int i = 0; i < nums1.size(); i++) {
            res[i] = m[nums1[i]];
        }
        return res;
    }
};
```


## 相关话题

- [栈](https://leetcode-cn.com/tag/stack) 
- [数组](https://leetcode-cn.com/tag/array) 
- [哈希表](https://leetcode-cn.com/tag/hash-table) 
- [单调栈](https://leetcode-cn.com/tag/monotonic-stack) 


## 相似题目

- [每日温度](../daily-temperatures/README.md)  [Medium] 


## Links

- [Prev](../guess-number-higher-or-lower/README.md) 
- [Next](../number-of-provinces/README.md) 
