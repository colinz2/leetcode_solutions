
# [括号生成](https://leetcode-cn.com/problems/generate-parentheses)

## 题目描述

<p>数字 <code>n</code>&nbsp;代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 <strong>有效的 </strong>括号组合。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>["((()))","(()())","(())()","()(())","()()()"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>["()"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 8</code></li>
</ul>


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

- [字符串](https://leetcode-cn.com/tag/string) 
- [动态规划](https://leetcode-cn.com/tag/dynamic-programming) 
- [回溯](https://leetcode-cn.com/tag/backtracking) 


## 相似题目

- [电话号码的字母组合](../letter-combinations-of-a-phone-number/README.md)  [Medium] 
- [有效的括号](../valid-parentheses/README.md)  [Easy] 


## Links

- [Prev](../merge-two-sorted-lists/README.md) 
- [Next](../merge-k-sorted-lists/README.md) 

