
# [](https://leetcode-cn.com/problems/letter-case-permutation)

## 题目描述



## 题解

### cpp [🔗](letter-case-permutation.cpp) 
```cpp
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        if (S.size() == 0) return {S};
        FindLetterCasePermutation(S, 0, "", res);
        return res;
    }
    void FindLetterCasePermutation(string S, int index, string t, vector<string>& res) {
        if (t.size() == S.size()) {
            res.push_back(t);
            return ;
        }

        if (isalpha(S[index])) {
            char c = isupper(S[index]) ? tolower(S[index]) : toupper(S[index]);
            FindLetterCasePermutation(S, index + 1, t + c, res);

        }
        FindLetterCasePermutation(S, index + 1, t + S[index], res);
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../binary-search/README.md) 
- [Next](../rotated-digits/README.md) 

