
# [](https://leetcode-cn.com/problems/largest-number)

## 题目描述



## 题解

### cpp [🔗](largest-number.cpp) 
```cpp
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](int a, int b) {
            string sa = std::to_string(a), sb = std::to_string(b);
            return sa + sb > sb + sa;
        });

        if (nums[0] == 0) return "0";
        
        std::string res;
        for (auto n : nums) {
            res += std::to_string(n);
        }
        return res;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../second-highest-salary/README.md) 
- [Next](../rotate-array/README.md) 

