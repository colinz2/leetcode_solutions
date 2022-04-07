
# [](https://leetcode-cn.com/problems/one-edit-distance)

## 题目描述



## 题解

### cpp [🔗](one-edit-distance.cpp) 
```cpp
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        // let len of s > t
        int distance = s.size() - t.size();
        if (distance < 0) {
            return isOneEditDistance(t, s);
        }
        if (distance > 1) {
            return false;
        }

        int len = t.size();
        for (int i = 0; i < len; i++) {
            if (s[i] != t[i]) {
                if (distance > 0) {
                    return s.substr(i+1) == t.substr(i);
                } else {
                    return s.substr(i+1) == t.substr(i+1);
                }
            }
        }
        return distance > 0;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../intersection-of-two-linked-lists/README.md) 
- [Next](../find-peak-element/README.md) 

