
# [](https://leetcode-cn.com/problems/maximum-number-of-balloons)

## 题目描述



## 题解

### cpp [🔗](maximum-number-of-balloons.cpp) 
```cpp
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[128] = {0,};
        for (auto c : text) {
            freq[c]++;
        }
        int m1 = std::min(freq['l']/2, freq['o']/2);
        return std::min({freq['b'], freq['a'], freq['n'], m1});
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../longest-common-subsequence/README.md) 
- [Next](../fizz-buzz-multithreaded/README.md) 

