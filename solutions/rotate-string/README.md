
# [](https://leetcode-cn.com/problems/rotate-string)

## 题目描述



## 题解

### cpp [🔗](rotate-string.cpp) 
```cpp
class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.size() != B.size()) return false;
        
        return (A + A).find(B) != string::npos;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../number-of-matching-subsequences/README.md) 
- [Next](../design-hashset/README.md) 

