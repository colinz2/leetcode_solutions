
# [](https://leetcode-cn.com/problems/sum-of-two-integers)

## 题目描述



## 题解

### cpp [🔗](sum-of-two-integers.cpp) 
```cpp
class Solution {
public:
    int getSum(int a, int b) {
        //使用符号了
        //return a + b;
        int sum = a;
        while (b != 0) {
            sum = a ^ b;//calculate sum of a and b without thinking the carry 
            b = (a & b) << 1;//calculate the carry
            a = sum;//add sum(without carry) and carry
        }
        return sum;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../plus-one-linked-list/README.md) 
- [Next](../guess-number-higher-or-lower/README.md) 

