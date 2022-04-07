
# [](https://leetcode-cn.com/problems/reverse-words-in-a-string)

## 题目描述



## 题解

### cpp [🔗](reverse-words-in-a-string.cpp) 
```cpp
class Solution {
public:
    void reverseWords(string &s) {
        vector<string> elems = split(s);
        if (elems.size() == 0) {
            s = "";
            return ;
        }
        vector<string>::reverse_iterator r_iter;
        for (r_iter = elems.rbegin(); r_iter != elems.rend(); r_iter++) {
            if (r_iter != elems.rbegin())
                s += " " + *r_iter;
            else s = *r_iter;
        }
    }

private:
    vector<string> split(const string &s) {
        vector<string> res;
        int start = nextNonSpace(s, 0);
        for (int i = start + 1; i <= s.size();)
            if (i == s.size() || s[i] == ' ') {
                res.push_back(s.substr(start, i - start));
                start = nextNonSpace(s, i);
                i = start + 1;
            } else
                i++;
        return res;
    }

    int nextNonSpace(const string &s, int start) {
        int i = start;
        for (; i < s.size(); i++)
            if (s[i] != ' ')
                return i;
        return i;
    };
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../evaluate-reverse-polish-notation/README.md) 
- [Next](../min-stack/README.md) 

