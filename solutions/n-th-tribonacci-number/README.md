
# [](https://leetcode-cn.com/problems/n-th-tribonacci-number)

## 题目描述



## 题解

### cpp [🔗](n-th-tribonacci-number.cpp) 
```cpp
class Solution {
public:
    int tribonacci(int n) {
        int tri[4] = {0,1,};
        for (int i = 1; i <=n; i++) {
            tri[0] = tri[1];
            tri[1] = tri[2];
            tri[2] = tri[3];
            tri[3] = tri[0] + tri[1] + tri[2];
        }
        return tri[3];
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../print-zero-even-odd/README.md) 
- [Next](../decompress-run-length-encoded-list/README.md) 

