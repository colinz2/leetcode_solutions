
# [](https://leetcode-cn.com/problems/group-anagrams)

## 题目描述



## 题解

### cpp [🔗](group-anagrams.cpp) 
```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> smap;
        vector<vector<string>> res;
        for (auto &s : strs) {
            string tmp(s);
            sort(tmp.begin(), tmp.end());
            smap[tmp].push_back(s);
        }
        for (auto &m : smap) {
            res.emplace_back(m.second);
        }

        return res;        
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../rotate-image/README.md) 
- [Next](../powx-n/README.md) 

