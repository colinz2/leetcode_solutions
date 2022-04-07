
# [](https://leetcode-cn.com/problems/missing-number)

## 题目描述



## 题解

### c [🔗](missing-number.c) 
```c
int missingNumber(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++)
        result ^= nums[i]^(i+1);
    return result;
}
```
### cpp [🔗](missing-number.cpp) 
```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        auto sum = std::accumulate(nums.begin(), nums.end(), 0);
        auto size = nums.size();
        return  (size * (size + 1) /2) - sum;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../palindrome-permutation/README.md) 
- [Next](../closest-binary-search-tree-value/README.md) 

