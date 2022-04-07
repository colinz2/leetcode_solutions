
# [](https://leetcode-cn.com/problems/house-robber-ii)

## 题目描述



## 题解

### cpp [🔗](house-robber-ii.cpp) 
```cpp
class Solution {
public:
    //  在不偷窃第一个房子的情况下
    //  在不偷窃最后一个房子的情况下
    int rob(vector<int>& nums) {
        auto cnt = nums.size();
        if (cnt == 0) {
            return 0;
        } else if (cnt == 1) {
            return nums[0]; 
        }
        return max(robRange(nums, 0, cnt - 1), robRange(nums, 1, cnt));
    }

    int robRange(vector<int>& nums, int start, int end) {
        int curr = 0;
        int pre = 0;
        for (int i = start; i < end; i++) {
            auto tmp = max(curr, pre + nums[i]);
            pre = curr;
            curr = tmp;
        }
        return curr;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../design-add-and-search-words-data-structure/README.md) 
- [Next](../kth-largest-element-in-an-array/README.md) 

