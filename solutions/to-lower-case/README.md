
# [](https://leetcode-cn.com/problems/to-lower-case)

## 题目描述



## 题解

### cpp [🔗](to-lower-case.cpp) 
```cpp
class Solution {
public:
    string toLowerCase(string str) {
        for (auto &c : str) {
            c = tolower(c);
        }
        return str;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../daily-temperatures/README.md) 
- [Next](../find-smallest-letter-greater-than-target/README.md) 

