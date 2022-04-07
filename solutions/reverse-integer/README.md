
# [](https://leetcode-cn.com/problems/reverse-integer)

## 题目描述



## 题解

### cpp [🔗](reverse-integer.cpp) 
```cpp
class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while (x != 0) {
            // 这里不用判断取余了，因为 x 也是 int
            if (ret > INT_MAX/10 || ret  < INT_MIN/10) {
                return 0;
            }
            ret = ret * 10 + x%10;
            x /= 10;
        }
        return ret;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../longest-palindromic-substring/README.md) 
- [Next](../string-to-integer-atoi/README.md) 

