
# [搜索插入位置](https://leetcode-cn.com/problems/search-insert-position)

## 题目描述

<p>给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。</p>

<p>请必须使用时间复杂度为 <code>O(log n)</code> 的算法。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,3,5,6], target = 5
<strong>输出:</strong> 2
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,3,5,6], target = 2
<strong>输出:</strong> 1
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,3,5,6], target = 7
<strong>输出:</strong> 4
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code> 为&nbsp;<strong>无重复元素&nbsp;</strong>的&nbsp;<strong>升序&nbsp;</strong>排列数组</li>
	<li><code>-10<sup>4</sup> &lt;= target &lt;= 10<sup>4</sup></code></li>
</ul>


## 题解

### cpp [🔗](search-insert-position.cpp) 
```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int j = 0, k = nums.size();
        while (j < k) {
            int m = j + (k -j )/2;
            if (nums[m] < target) {
                j = m + 1;
            } else  {
                k = m; 
            }
        }
        return k;
    }
};
```
### python3 [🔗](search-insert-position.py) 
```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        i, j = 0, len(nums)
        while i < j:
            m = (i + j)//2
            if nums[m] < target:
                i = m + 1
            else:
                j = m
        
        return i
```
### golang [🔗](search-insert-position.go) 
```golang
func searchInsert(nums []int, target int) int {
    j, k := 0, len(nums)-1
    for j <= k {
        m := j + (k - j)/2
        if nums[m] == target {
            return m
        } else if nums[m] < target {
            j = m + 1
        } else {
            k = m - 1
        }
    }
    return j;
}
```


## 相关话题

- [数组](../../tags/array.md) 
- [二分查找](../../tags/binary-search.md) 


## 相似题目

- [第一个错误的版本](../first-bad-version/README.md)  [Easy] 


## Links

- [Prev](../find-first-and-last-position-of-element-in-sorted-array/README.md) 
- [Next](../count-and-say/README.md) 

