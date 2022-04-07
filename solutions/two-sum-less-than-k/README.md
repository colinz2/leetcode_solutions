
# [](https://leetcode-cn.com/problems/two-sum-less-than-k)

## 题目描述



## 题解

### cpp [🔗](two-sum-less-than-k.cpp) 
```cpp
class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int res = -1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int tmp = nums[i] + nums[j];
                if (tmp < k) {
                    res = max(res, tmp);
                }
            }
        }
        return res;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../video-stitching/README.md) 
- [Next](../check-if-a-number-is-majority-element-in-a-sorted-array/README.md) 

