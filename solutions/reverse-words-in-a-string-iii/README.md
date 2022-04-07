
# [](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii)

## 题目描述



## 题解

### cpp [🔗](reverse-words-in-a-string-iii.cpp) 
```cpp
class Solution {
private:
    void reverse(string& s, int l, int r) {
        //[l, r]
        while (l < r) {
            swap(s[l++], s[r--]);
        }
    }

public:
    string reverseWords(string s) {
        int b = 0, e = 0;
        for (int i = 0; i < s.size(); i++) {
            while (isblank(s[i])) {
                i++;
                b = i;
            }
            if (i + 1 == s.size() || isblank(s[i + 1])) {
                e = i;
                reverse(s, b, e);
            }
        }
        return s;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../student-attendance-record-i/README.md) 
- [Next](../subarray-sum-equals-k/README.md) 

