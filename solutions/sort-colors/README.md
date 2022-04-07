
# [](https://leetcode-cn.com/problems/sort-colors)

## 题目描述



## 题解

### cpp [🔗](sort-colors.cpp) 
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cnt(3);
        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
        }

        int k = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                nums[k++] = i;
            }
        }
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../search-a-2d-matrix/README.md) 
- [Next](../combinations/README.md) 

