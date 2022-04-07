
# [](https://leetcode-cn.com/problems/ugly-number-ii)

## 题目描述



## 题解

### cpp [🔗](ugly-number-ii.cpp) 
```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1, 1);
        int i2 = 0, i3 = 0, i5 = 0;
        while (res.size() < n) {
            int m2 = res[i2] * 2, m3 = res[i3] * 3, m5 = res[i5] * 5;
            int mn = min(m2, min(m3, m5));
            if (mn == m2) ++i2;
            if (mn == m3) ++i3;
            if (mn == m5) ++i5;
            res.push_back(mn);
        }
        return res.back();
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../ugly-number/README.md) 
- [Next](../palindrome-permutation/README.md) 

