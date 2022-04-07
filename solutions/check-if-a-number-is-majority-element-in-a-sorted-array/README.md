
# [](https://leetcode-cn.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array)

## 题目描述



## 题解

### golang [🔗](check-if-a-number-is-majority-element-in-a-sorted-array.go) 
```golang
func isMajorityElement(nums []int, target int) bool {
    j , k := 0, len(nums)
    for j < k {
        m := (j+k)>>1
        if nums[m] < target {
            j = m + 1
        } else {
            k = m
        }
    }
    j += len(nums)/2
    return j < len(nums) && nums[j] == target
}
```
### c [🔗](check-if-a-number-is-majority-element-in-a-sorted-array.c) 
```c
bool isMajorityElement(int* nums, int numsSize, int target){
    int start = 0, end = numsSize-1;
    int targetSize = 0;
    while (start < end) {
        if (nums[start] != target) {
            start++;
        } else if (nums[end] != target) {
            end--;
        }
        if (targetSize == end-start+1) {
            return targetSize > numsSize/2;
        } else {
            targetSize = end-start+1;
        }
    }
    return false;
}
```
### cpp [🔗](check-if-a-number-is-majority-element-in-a-sorted-array.cpp) 
```cpp
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int cnt = 0;
        for (auto n : nums) {
            if (target == n) cnt++;
            else if (target < n) break;
        }
        return cnt > nums.size()/2;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../two-sum-less-than-k/README.md) 
- [Next](../binary-search-tree-to-greater-sum-tree/README.md) 

