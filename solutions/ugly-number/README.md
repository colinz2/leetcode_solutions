
# [](https://leetcode-cn.com/problems/ugly-number)

## 题目描述



## 题解

### cpp [🔗](ugly-number.cpp) 
```cpp
class Solution {
public:
    bool isUgly(int num) {
        if (num < 1) return false;
            while (num %2 == 0) num >>= 1;
            while (num%3 == 0) num /= 3;
            while (num%5 == 0 ) num /= 5;
        return num == 1;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../add-digits/README.md) 
- [Next](../ugly-number-ii/README.md) 

