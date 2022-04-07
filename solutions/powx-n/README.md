
# [](https://leetcode-cn.com/problems/powx-n)

## 题目描述



## 题解

### cpp [🔗](powx-n.cpp) 
```cpp
class Solution {
public:
    double quickMul(double x, long long N) {
        if (N == 0) {
            return 1.0;
        }
        double y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../group-anagrams/README.md) 
- [Next](../maximum-subarray/README.md) 

