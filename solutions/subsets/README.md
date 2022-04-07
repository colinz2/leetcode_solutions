
# [](https://leetcode-cn.com/problems/subsets)

## 题目描述



## 题解

### cpp [🔗](subsets.cpp) 
```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> one;
        FindSubsets(nums, 0, one, res);
        return res;
    }

private:
    void FindSubsets(vector<int>& nums, int index, vector<int>& one, vector<vector<int>>& res) {
        res.push_back(one);
        for (int i = index; i < nums.size(); i++) {
            one.push_back(nums[i]);
            FindSubsets(nums, i + 1, one, res);
            one.pop_back();
        }
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../combinations/README.md) 
- [Next](../word-search/README.md) 

