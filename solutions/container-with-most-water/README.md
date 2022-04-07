
# [](https://leetcode-cn.com/problems/container-with-most-water)

## 题目描述



## 题解

### cpp [🔗](container-with-most-water.cpp) 
```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int j = 0, k = height.size() - 1;
        int max_area = 0;
        while (j < k) {
            int min_height = std::min(height[k], height[j]);
            int area = (k - j) * min_height;
            max_area = std::max(max_area, area);
            if (min_height == height[k]) {
                k--;
            } else {
                j++;
            }
        }
        return max_area;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../palindrome-number/README.md) 
- [Next](../roman-to-integer/README.md) 

