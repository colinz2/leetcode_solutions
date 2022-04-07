
# [](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted)

## 题目描述



## 题解

### cpp [🔗](two-sum-ii-input-array-is-sorted.cpp) 
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        if (numbers.size() < 2) return {};
        while (l < r) {
            if (numbers[l] + numbers[r] == target) {
                return {l + 1, r + 1};
            } else if (numbers[l] + numbers[r] > target) {
                r--;
            } else {
                l++;
            }
        }
        return {};
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../missing-ranges/README.md) 
- [Next](../majority-element/README.md) 

