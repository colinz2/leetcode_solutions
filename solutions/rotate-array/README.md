
# [](https://leetcode-cn.com/problems/rotate-array)

## 题目描述



## 题解

### cpp [🔗](rotate-array.cpp) 
```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto size = nums.size();
        if (size == 1) {
            return ;
        }
        for (auto i = 0; i < k; i++) {
            auto f = nums[0];
            auto e = nums[size - 1];
            for (auto j = size - 1; j > 1; j--) {
                nums[j] = nums[j - 1]; 
            }
            nums[1] = f;
            nums[0] = e;
            //auto new_index = (i + k) % size;
        }
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../largest-number/README.md) 
- [Next](../reverse-bits/README.md) 

