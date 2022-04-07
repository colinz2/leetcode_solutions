
# [](https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array)

## 题目描述



## 题解

### cpp [🔗](find-all-numbers-disappeared-in-an-array.cpp) 
```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            int index = (nums[i] - 1) % len;
            nums[index] += len;
        }
        for (int i = 0; i < len; i++) {
            if (nums[i] <= len) {
                res.push_back(i+1);
            }
        }
        return res;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../add-two-numbers-ii/README.md) 
- [Next](../sort-characters-by-frequency/README.md) 

