
# [](https://leetcode-cn.com/problems/generate-parentheses)

## 题目描述



## 题解

### cpp [🔗](generate-parentheses.cpp) 
```cpp
class Solution {
private:
    unordered_set<string> gen_set;
public:
    void generateParenthesisDFS(int left, int right, string s, vector<string>& res) {
        if (left > right) return;
        if (left == 0 && right == 0) {
            res.push_back(s);
        } else {
            if (left)
                generateParenthesisDFS(left - 1, right, s + "(", res);
            if (right)
                generateParenthesisDFS(left, right - 1, s + ")", res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n < 1) return res;
        generateParenthesisDFS(n, n, "", res);
        return res;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../merge-two-sorted-lists/README.md) 
- [Next](../merge-k-sorted-lists/README.md) 

