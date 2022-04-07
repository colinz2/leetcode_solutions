
# [](https://leetcode-cn.com/problems/maximum-subarray)

## 题目描述



## 题解

### cpp [🔗](maximum-subarray.cpp) 
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (sum < 0) {
                sum = nums[i];
            } else {
                sum += nums[i];
            }

            if (sum > max_sum) {
                max_sum = sum;
            }
        }
        return max_sum;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../powx-n/README.md) 
- [Next](../spiral-matrix/README.md) 

