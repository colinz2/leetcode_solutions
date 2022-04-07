
# [两个数组的交集](https://leetcode-cn.com/problems/intersection-of-two-arrays)

## 题目描述

<p>给定两个数组&nbsp;<code>nums1</code>&nbsp;和&nbsp;<code>nums2</code> ，返回 <em>它们的交集</em>&nbsp;。输出结果中的每个元素一定是 <strong>唯一</strong> 的。我们可以 <strong>不考虑输出结果的顺序</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1,2,2,1], nums2 = [2,2]
<strong>输出：</strong>[2]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [4,9,5], nums2 = [9,4,9,8,4]
<strong>输出：</strong>[9,4]
<strong>解释：</strong>[4,9] 也是可通过的
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 1000</code></li>
</ul>


## 题解

### python3 [🔗](intersection-of-two-arrays.py) 
```python3
class Solution:
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        a = set(nums1)
        b = set(nums2)
        c = a & b
        return list(c)
        
```
### cpp [🔗](intersection-of-two-arrays.cpp) 
```cpp
class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> n1(nums1.begin(), nums1.end());
        unordered_set<int> n2(nums2.begin(), nums2.end());
        vector<int> ret;

        for (auto c : n2) {
            if (n1.find(c) != n1.end()) {
                ret.push_back(c);
            }
        }
        return ret;
    }
};
```
### golang [🔗](intersection-of-two-arrays.go) 
```golang
func intersection(nums1 []int, nums2 []int) []int {
	numMap1 := make(map[int]struct{})
	resMap := make(map[int]struct{})
	var res []int
	for _, n := range nums1 {
		numMap1[n] = struct{}{}
	}
	for _, n := range nums2 {
		if _, e := numMap1[n]; e {
			if _, e := resMap[n]; !e {
				res = append(res, n)
				resMap[n] = struct{}{}
			}
		}
	}
	return res
}

```


## 相关话题

- [数组](../../tags/array.md) 
- [哈希表](../../tags/hash-table.md) 
- [双指针](../../tags/two-pointers.md) 
- [二分查找](../../tags/binary-search.md) 
- [排序](../../tags/sorting.md) 


## 相似题目

- [两个数组的交集 II](../intersection-of-two-arrays-ii/README.md)  [Easy] 


## Links

- [Prev](../top-k-frequent-elements/README.md) 
- [Next](../intersection-of-two-arrays-ii/README.md) 

