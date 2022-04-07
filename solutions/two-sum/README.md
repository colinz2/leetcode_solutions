
# [](https://leetcode-cn.com/problems/two-sum)

## 题目描述



## 题解

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


## 相关话题



## 相似题目



## Links

- [Next](../add-two-numbers/README.md) 

