
# [多数元素](https://leetcode-cn.com/problems/majority-element)

## 题目描述

<p>给定一个大小为 <em>n </em>的数组，找到其中的多数元素。多数元素是指在数组中出现次数 <strong>大于</strong> <code>⌊ n/2 ⌋</code> 的元素。</p>

<p>你可以假设数组是非空的，并且给定的数组总是存在多数元素。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>[3,2,3]
<strong>输出：</strong>3</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>[2,2,1,1,1,2,2]
<strong>输出：</strong>2
</pre>

<p> </p>

<p><strong>进阶：</strong></p>

<ul>
	<li>尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。</li>
</ul>


## 题解

### cpp [🔗](majority-element.cpp) 
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = -1, cnt = 0;
        for (auto n : nums) {
            if (cnt == 0) {
                res = n;
            }
            if (res == n) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return res;
    }
};
```
### golang [🔗](majority-element.go) 
```golang
func majorityElement(nums []int) int {
	res, count := nums[0], 0
	for i := 0; i < len(nums); i++ {
		if count == 0 {
			res, count = nums[i], 1
		} else {
			if nums[i] == res {
				count++
			} else {
				count--
			}
		}
	}
	return res
}
```
### python3 [🔗](majority-element.py) 
```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        ans, count = 0, 0
        for x in nums:
            ans = x if count == 0  else ans
            count = count + 1 if ans == x else count - 1

        return ans
```


## 相关话题

- [数组](../../tags/array.md) 
- [哈希表](../../tags/hash-table.md) 
- [分治](../../tags/divide-and-conquer.md) 
- [计数](../../tags/counting.md) 
- [排序](../../tags/sorting.md) 


## 相似题目

- [检查一个数是否在数组中占绝大多数](../check-if-a-number-is-majority-element-in-a-sorted-array/README.md)  [Easy] 


## Links

- [Prev](../two-sum-ii-input-array-is-sorted/README.md) 
- [Next](../excel-sheet-column-number/README.md) 

