
# [](https://leetcode-cn.com/problems/distribute-candies)

## 题目描述



## 题解

### cpp [🔗](distribute-candies.cpp) 
```cpp
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> set(candyType.begin(), candyType.end());
        return std::min(set.size(), candyType.size()/2);    
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../subarray-sum-equals-k/README.md) 
- [Next](../kill-process/README.md) 

