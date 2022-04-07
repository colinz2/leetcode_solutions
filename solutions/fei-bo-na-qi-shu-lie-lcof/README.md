
# [](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof)

## 题目描述



## 题解

### cpp [🔗](fei-bo-na-qi-shu-lie-lcof.cpp) 
```cpp
class Solution {
public:
    int fib(int n) {
        int MOD = 1000000007;
        vector<int> fibs(n+2);
        fibs[1] = 1;

        std::function<int(int)> fib_iter = [&](int n) {
            if (fibs[n] > 0 || n == 0) {
                return fibs[n];
            }
            int a = fib_iter(n-2) % MOD;
            int b = fib_iter(n-1) % MOD;
            fibs[n] = (a + b) % MOD;
            return fibs[n];
        };
        return fib_iter(n);
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../yong-liang-ge-zhan-shi-xian-dui-lie-lcof/README.md) 
- [Next](../shu-zu-zhong-zhong-fu-de-shu-zi-lcof/README.md) 

