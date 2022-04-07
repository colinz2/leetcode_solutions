
# [](https://leetcode-cn.com/problems/group-shifted-strings)

## 题目描述



## 题解

### cpp [🔗](group-shifted-strings.cpp) 
```cpp
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> smap;
        for (auto& s : strings) {
            string tmp(s);
            std::transform(tmp.begin(), tmp.end(), tmp.begin(), [&s](char c) {
                return (c - (s[0]-'a') + 26)%26;
            });
            smap[tmp].push_back(s); 
        }

        for (auto &p : smap) {
            res.emplace_back(p.second);
        }
        return res;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../valid-anagram/README.md) 
- [Next](../flatten-2d-vector/README.md) 

