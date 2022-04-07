
# [](https://leetcode-cn.com/problems/trapping-rain-water)

## 题目描述



## 题解

### cpp [🔗](trapping-rain-water.cpp) 
```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int maxLeft = height[0];
        int maxRight = height[height.size()-1];

        int res = 0;
        while (left < right) {
            maxLeft = std::max(maxLeft, height[left]);
            maxRight = std::max(maxRight, height[right]);
            if (height[left] < height[right]) {
                res += maxLeft - height[left];
                left++;
            } else {
                res += maxRight - height[right];
                right--;
            }
        }
        return res;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../combination-sum/README.md) 
- [Next](../multiply-strings/README.md) 

