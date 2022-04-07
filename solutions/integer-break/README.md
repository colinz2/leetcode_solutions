
# [](https://leetcode-cn.com/problems/integer-break)

## 题目描述



## 题解

### cpp [🔗](integer-break.cpp) 
```cpp
class Solution {
public:
    int integerBreak(int n) {
        vector<int>memo(n + 1, 1);
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                int max_tmp = max(j * (i - j), j * memo[i - j]);
                memo[i] = max(memo[i], max_tmp);
            }
        }
        return memo[n];
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../counting-bits/README.md) 
- [Next](../reverse-string/README.md) 

