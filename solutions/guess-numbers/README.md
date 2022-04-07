
# [](https://leetcode-cn.com/problems/guess-numbers)

## 题目描述



## 题解

### cpp [🔗](guess-numbers.cpp) 
```cpp
class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        if (guess.size() != answer.size())
            return 0;
        int cnt = 0;
        for (int i = 0; i < guess.size(); i++) {
            if (guess[i] == answer[i]) {
                cnt++;
            }
        }
        return cnt;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../count-elements-with-strictly-smaller-and-greater-elements/README.md) 
- [Next](../is-unique-lcci/README.md) 

