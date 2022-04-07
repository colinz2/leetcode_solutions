
# [](https://leetcode-cn.com/problems/subsets-ii)

## 题目描述



## 题解

### cpp [🔗](subsets-ii.cpp) 
```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        std::sort(nums.begin(), nums.end());
        backtrace(res, 0, nums, tmp);
        return res;          
    }

    void backtrace(vector<vector<int>>& res, int index, vector<int>& nums, vector<int>& tmp) {
        res.push_back(tmp);
        for (int i = index; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            backtrace(res, i+1, nums, tmp);
            tmp.pop_back();
            while (i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        }
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../gray-code/README.md) 
- [Next](../reverse-linked-list-ii/README.md) 

