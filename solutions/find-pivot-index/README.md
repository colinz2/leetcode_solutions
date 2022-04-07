
# [](https://leetcode-cn.com/problems/find-pivot-index)

## 题目描述



## 题解

### c [🔗](find-pivot-index.c) 
```c
// sum + nums[i] + sum = total
// 2sum = total = num[i]
int pivotIndex(int* nums, int numsSize){
    int total = 0, sum = 0;
    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        if (sum + sum + nums[i] == total) {
            return i;
        }
        sum += nums[i];
    }

    return -1;
}
```
### cpp [🔗](find-pivot-index.cpp) 
```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int lo = 0, l_sum = 0;
        while (lo < nums.size()) {
            if (l_sum == sum - nums[lo]) {
                return lo;
            } else {
                l_sum += nums[lo];
                sum -= nums[lo];
                lo++;
            }
        }
        return -1;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../1-bit-and-2-bit-characters/README.md) 
- [Next](../split-linked-list-in-parts/README.md) 

