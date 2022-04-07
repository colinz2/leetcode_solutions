
# [](https://leetcode-cn.com/problems/first-unique-character-in-a-string)

## 题目描述



## 题解

### cpp [🔗](first-unique-character-in-a-string.cpp) 
```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        int cnt[256] = {0};
        for (auto &c : s) {
            cnt[c] += 1;
        }
        for (int i = 0; i < s.size(); i++) {
            if (cnt[s[i]] == 1) return i;
        }
        return -1;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../lexicographical-numbers/README.md) 
- [Next](../find-the-difference/README.md) 

