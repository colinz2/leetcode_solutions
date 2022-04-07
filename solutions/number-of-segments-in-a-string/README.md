
# [](https://leetcode-cn.com/problems/number-of-segments-in-a-string)

## 题目描述



## 题解

### cpp [🔗](number-of-segments-in-a-string.cpp) 
```cpp
class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) 
            res += s[i] != ' ' && (i + 1 == s.size() || s[i + 1] == ' ');
        return res;
    }
};


```


## 相关话题



## 相似题目



## Links

- [Prev](../add-strings/README.md) 
- [Next](../arranging-coins/README.md) 

