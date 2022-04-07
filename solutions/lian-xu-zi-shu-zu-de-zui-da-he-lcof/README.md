
# [](https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof)

## 题目描述



## 题解

### cpp [🔗](lian-xu-zi-shu-zu-de-zui-da-he-lcof.cpp) 
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0], sum = 0;
        for (auto num : nums) {
            if (sum < 0) {
                sum = num;
            } else {
                sum += num;
            }
            max_sum = std::max(max_sum, sum);
        }
        return max_sum;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../zui-xiao-de-kge-shu-lcof/README.md) 
- [Next](../que-shi-de-shu-zi-lcof/README.md) 

