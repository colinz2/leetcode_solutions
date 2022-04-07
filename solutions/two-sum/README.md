
# [两数之和](https://leetcode-cn.com/problems/two-sum)

## 题目描述

<p>给定一个整数数组 <code>nums</code>&nbsp;和一个整数目标值 <code>target</code>，请你在该数组中找出 <strong>和为目标值 </strong><em><code>target</code></em>&nbsp; 的那&nbsp;<strong>两个</strong>&nbsp;整数，并返回它们的数组下标。</p>

<p>你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。</p>

<p>你可以按任意顺序返回答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,7,11,15], target = 9
<strong>输出：</strong>[0,1]
<strong>解释：</strong>因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,2,4], target = 6
<strong>输出：</strong>[1,2]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,3], target = 6
<strong>输出：</strong>[0,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= target &lt;= 10<sup>9</sup></code></li>
	<li><strong>只会存在一个有效答案</strong></li>
</ul>

<p><strong>进阶：</strong>你可以想出一个时间复杂度小于 <code>O(n<sup>2</sup>)</code> 的算法吗？</p>


## 题解

### golang [🔗](two-sum.go) 
```golang
func twoSum(nums []int, target int) []int {
    seen := make(map[int]int)
    for i, num := range nums {
        if val, e := seen[target - num]; e {
            return []int{val, i}
        }
        seen[num] = i
    }
    return []int{-1, -1}
}
```
### python3 [🔗](two-sum.py) 
```python3
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        check_dict = dict()
        for i, n in enumerate(nums):
            c = target - n
            if c in check_dict:
                return [check_dict[c], i]
            check_dict[n] = i
```
### rust [🔗](two-sum.rs) 
```rust

use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut seen: HashMap<i32 ,i32> = HashMap::new();
        for (i, v) in nums.iter().enumerate() {
            match seen.get(v) {
                Some(index) => {
                    return vec![*index, i as i32];
                }
                None => {
                    seen.insert(target - v, i as i32); 
                }
            }
        }
        vec![]
    }
}
```
### cpp [🔗](two-sum.cpp) 
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++) {
            auto it = seen.find(target - nums[i]);
            if (it != seen.end()) {
                return {it->second, i};
            }
            seen[nums[i]] = i;
        }
        return {-1, -1};
    }
};
```


## 相关话题

- [数组](../../tags/array.md) 
- [哈希表](../../tags/hash-table.md) 


## 相似题目

- [三数之和](../3sum/README.md)  [Medium] 
- [两数之和 II - 输入有序数组](../two-sum-ii-input-array-is-sorted/README.md)  [Medium] 
- [和为 K 的子数组](../subarray-sum-equals-k/README.md)  [Medium] 
- [两数之和 IV - 输入 BST](../two-sum-iv-input-is-a-bst/README.md)  [Easy] 
- [小于 K 的两数之和](../two-sum-less-than-k/README.md)  [Easy] 


## Links

- [Next](../add-two-numbers/README.md) 

