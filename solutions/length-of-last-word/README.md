
# [](https://leetcode-cn.com/problems/length-of-last-word)

## 题目描述



## 题解

### cpp [🔗](length-of-last-word.cpp) 
```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() < 1) return 0;
        int cnt =0;
        bool _space_end = true;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                _space_end = false;
                cnt++;
            } else if (_space_end) {
                continue;
            } else {
                break;
            }
        }
        return cnt;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../merge-intervals/README.md) 
- [Next](../spiral-matrix-ii/README.md) 

