
# [](https://leetcode-cn.com/problems/palindrome-number)

## 题目描述



## 题解

### cpp [🔗](palindrome-number.cpp) 
```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        long long ret = 0;
        long long y = x;
        while (x != 0) {
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        return y == ret && y >= 0;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../string-to-integer-atoi/README.md) 
- [Next](../container-with-most-water/README.md) 

