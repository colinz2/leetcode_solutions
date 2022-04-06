
# [字母大小写全排列](https://leetcode-cn.com/problems/letter-case-permutation)

## 题目描述

<p>给定一个字符串&nbsp;<code>s</code>&nbsp;，通过将字符串&nbsp;<code>s</code>&nbsp;中的每个字母转变大小写，我们可以获得一个新的字符串。</p>

<p>返回 <em>所有可能得到的字符串集合</em> 。以 <strong>任意顺序</strong> 返回输出。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "a1b2"
<strong>输出：</strong>["a1b2", "a1B2", "A1b2", "A1B2"]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> s = "3z4"
<strong>输出:</strong> ["3z4","3Z4"]
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 12</code></li>
	<li><code>s</code>&nbsp;由小写英文字母、大写英文字母和数字组成</li>
</ul>


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

- [位运算](https://leetcode-cn.com/tag/bit-manipulation) 
- [字符串](https://leetcode-cn.com/tag/string) 
- [回溯](https://leetcode-cn.com/tag/backtracking) 


## 相似题目

- [子集](../subsets/README.md)  [Medium] 


## Links

- [Prev](../binary-search/README.md) 
- [Next](../rotated-digits/README.md) 

