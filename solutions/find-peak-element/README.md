
# [](https://leetcode-cn.com/problems/find-peak-element)

## 题目描述



## 题解

### cpp [🔗](find-peak-element.cpp) 
```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            if (nums[mid] < nums[mid+1]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return hi;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../one-edit-distance/README.md) 
- [Next](../missing-ranges/README.md) 

