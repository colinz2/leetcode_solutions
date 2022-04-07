
# [](https://leetcode-cn.com/problems/sum-of-square-numbers)

## 题目描述



## 题解

### cpp [🔗](sum-of-square-numbers.cpp) 
```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        int max = (int)sqrt(c) + 1;
        for (int i = 0; i < max; i++) {
            int square = i*i;
            int sub_sqrt = sqrt(c - square);
            if (sub_sqrt*sub_sqrt + square == c) return true;
        }
        return false;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../maximum-product-of-three-numbers/README.md) 
- [Next](../average-of-levels-in-binary-tree/README.md) 

