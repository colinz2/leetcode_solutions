
# [](https://leetcode-cn.com/problems/single-number)

## 题目描述



## 题解

### cpp [🔗](single-number.cpp) 
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int yh = 0;
        int i = 0;
        for (; i + 3 < nums.size(); i += 4) {
            yh ^= nums[i];
            yh ^= nums[i+1];
            yh ^= nums[i+2];
            yh ^= nums[i+3];
        }

        for (; i < nums.size(); i++) {
            yh ^= nums[i];
        }
        return yh;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../surrounded-regions/README.md) 
- [Next](../copy-list-with-random-pointer/README.md) 

