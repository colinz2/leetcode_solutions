
# [](https://leetcode-cn.com/problems/assign-cookies)

## 题目描述



## 题解

### cpp [🔗](assign-cookies.cpp) 
```cpp
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int i = 0, j = 0;
        int ret = 0;
        while (i < g.size() && j < s.size()) {
            if (s[j] < g[i]) {
                j++;
            } else {
                j++;
                i++;
                ret++;
            }
        }
        return ret;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../sort-characters-by-frequency/README.md) 
- [Next](../repeated-substring-pattern/README.md) 

