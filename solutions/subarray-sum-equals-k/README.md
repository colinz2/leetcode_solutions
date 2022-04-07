
# [](https://leetcode-cn.com/problems/subarray-sum-equals-k)

## 题目描述



## 题解

### cpp [🔗](subarray-sum-equals-k.cpp) 
```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map{{0, 1}};
        int res = 0, sum = 0;
        for (auto num : nums) {
            sum += num;
            auto it = map.find(sum - k);
            if (it != map.end()) {
                res += it->second;
            }
            ++map[sum];
        }
        return res;   
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../reverse-words-in-a-string-iii/README.md) 
- [Next](../distribute-candies/README.md) 

