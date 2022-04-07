
# [](https://leetcode-cn.com/problems/counting-bits)

## 题目描述



## 题解

### cpp [🔗](counting-bits.cpp) 
```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1);
        for (int i = 1; i <= n; i++) {
            bits[i] = bits[i & (i - 1)] + 1;
        }
        return bits;
    }
};
```
### golang [🔗](counting-bits.go) 
```golang
func countBits(n int) []int {
    res := []int{}
    for i := 0; i < n+1 ; i++ {
        res = append(res, bitCount(i))
    }
    return res
}

func bitCount(n int) int {
    cnt := 0
    for n > 0 {
        n &= (n - 1)
        cnt++
    }
    return cnt
}
```


## 相关话题



## 相似题目



## Links

- [Prev](../house-robber-iii/README.md) 
- [Next](../integer-break/README.md) 

