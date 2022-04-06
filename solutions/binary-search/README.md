
# [二分查找](https://leetcode-cn.com/problems/binary-search)

## 题目描述

<p>给定一个&nbsp;<code>n</code>&nbsp;个元素有序的（升序）整型数组&nbsp;<code>nums</code> 和一个目标值&nbsp;<code>target</code> &nbsp;，写一个函数搜索&nbsp;<code>nums</code>&nbsp;中的 <code>target</code>，如果目标值存在返回下标，否则返回 <code>-1</code>。</p>

<p><br>
<strong>示例 1:</strong></p>

<pre><strong>输入:</strong> <code>nums</code> = [-1,0,3,5,9,12], <code>target</code> = 9
<strong>输出:</strong> 4
<strong>解释:</strong> 9 出现在 <code>nums</code> 中并且下标为 4
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> <code>nums</code> = [-1,0,3,5,9,12], <code>target</code> = 2
<strong>输出:</strong> -1
<strong>解释:</strong> 2 不存在 <code>nums</code> 中因此返回 -1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li>你可以假设 <code>nums</code>&nbsp;中的所有元素是不重复的。</li>
	<li><code>n</code>&nbsp;将在&nbsp;<code>[1, 10000]</code>之间。</li>
	<li><code>nums</code>&nbsp;的每个元素都将在&nbsp;<code>[-9999, 9999]</code>之间。</li>
</ol>


## 题解

### c [🔗](binary-search.c) 
```c
int search(int* nums, int numsSize, int target){
    int i = 0, j = numsSize;
    while (i < j) {
        int m = (i+j)>>1;
        if (nums[m] < target) {
            i = m + 1;
        } else if (nums[m] > target) {
            j = m;
        } else {
            return m; 
        }
    }
    return -1;
}
```
### cpp [🔗](binary-search.cpp) 
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l)/2;
            if (target > nums[mid]) {
                l = mid + 1;
            } else if (target < nums[mid]) {
                r = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
```
### golang [🔗](binary-search.go) 
```golang
func search(nums []int, target int) int {
    j, k := 0, len(nums)
    for j < k {
        m := (j + k) >> 1
        if nums[m] < target {
            j = m + 1
        } else if (nums[m] > target) {
            k = m
        } else {
            return m
        }
    }
    return -1
}
```
### python3 [🔗](binary-search.py) 
```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        i, j = 0, len(nums)
        while i < j:
            m = (i + j)//2
            if nums[m] == target:
                return m
            elif nums[m] < target:
                i = m + 1
            else:
                j = m

        return -1

```
### rust [🔗](binary-search.rs) 
```rust
impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut left = 0;
        let mut right = nums.len();
        while left < right {
            let mid = left + ((right - left) >> 1) ;
            if target == nums[mid] {
                return mid as i32;
            } else if target < nums[mid] {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
}
```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 
- [二分查找](https://leetcode-cn.com/tag/binary-search) 


## 相似题目

- [搜索长度未知的有序数组](../search-in-a-sorted-array-of-unknown-size/README.md)  [Medium] 


## Links

- [Prev](../kth-largest-element-in-a-stream/README.md) 
- [Next](../letter-case-permutation/README.md) 

