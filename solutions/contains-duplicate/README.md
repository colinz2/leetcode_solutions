
# [存在重复元素](https://leetcode-cn.com/problems/contains-duplicate)

## 题目描述

给你一个整数数组 <code>nums</code> 。如果任一值在数组中出现 <strong>至少两次</strong> ，返回 <code>true</code> ；如果数组中每个元素互不相同，返回 <code>false</code> 。
<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,1]
<strong>输出：</strong>true</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4]
<strong>输出：</strong>false</pre>

<p><strong>示例&nbsp;3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1,3,3,4,3,2,4,2]
<strong>输出：</strong>true</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


## 题解

### cpp [🔗](contains-duplicate.cpp) 
```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};
```


## 相关话题

- [数组](../../tags/array.md) 
- [哈希表](../../tags/hash-table.md) 
- [排序](../../tags/sorting.md) 


## 相似题目

- [存在重复元素 II](../contains-duplicate-ii/README.md)  [Easy] 


## Links

- [Prev](../kth-largest-element-in-an-array/README.md) 
- [Next](../contains-duplicate-ii/README.md) 

