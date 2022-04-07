
# [字符串解码](https://leetcode-cn.com/problems/decode-string)

## 题目描述

<p>给定一个经过编码的字符串，返回它解码后的字符串。</p>

<p>编码规则为: <code>k[encoded_string]</code>，表示其中方括号内部的 <code>encoded_string</code> 正好重复 <code>k</code> 次。注意 <code>k</code> 保证为正整数。</p>

<p>你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。</p>

<p>此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 <code>k</code> ，例如不会出现像&nbsp;<code>3a</code>&nbsp;或&nbsp;<code>2[4]</code>&nbsp;的输入。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "3[a]2[bc]"
<strong>输出：</strong>"aaabcbc"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "3[a2[c]]"
<strong>输出：</strong>"accaccacc"
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "2[abc]3[cd]ef"
<strong>输出：</strong>"abcabccdcdcdef"
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>s = "abc3[cd]xyz"
<strong>输出：</strong>"abccdcdcdxyz"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 30</code></li>
	<li><meta charset="UTF-8" /><code>s</code>&nbsp;由小写英文字母、数字和方括号<meta charset="UTF-8" />&nbsp;<code>'[]'</code> 组成</li>
	<li><code>s</code>&nbsp;保证是一个&nbsp;<strong>有效</strong>&nbsp;的输入。</li>
	<li><code>s</code>&nbsp;中所有整数的取值范围为<meta charset="UTF-8" />&nbsp;<code>[1, 300]</code>&nbsp;</li>
</ul>


## 题解

### cpp [🔗](decode-string.cpp) 
```cpp

class Solution {
public:
    string decodeString(string s) {
        int end;
        return dfs(s, 0, end);
    }

private:
    //s = "3[a]2[bc]", 返回 "aaabcbc".
    //s = "3[a2[c]]", 返回 "accaccacc".
    //s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".
    //\U0001f44c？,
    //\U0001f431啊
    string dfs(string s, int start, int& end) {
        string res = "";
        for (int i = start, b = 0; i < s.size();) {
            if (isdigit(s[i])) {
                int e, n;
                for (b = i; isdigit(s[i]); i++);
                n = stoi(s.substr(b, i - b));
                string sub = dfs(s, i, e);
                //cout << "sub = " << sub << endl;
                while (n--) res += sub;
                i = e;
            } else if (isalpha(s[i])) {
                res += s[i++];
            } else if (s[i] == ']') {
                i++;
                end = i;
                return res;
            } else {
                i++;
            }
        }
        return res;
    }
   
};
```


## 相关话题

- [栈](../../tags/stack.md) 
- [递归](../../tags/recursion.md) 
- [字符串](../../tags/string.md) 


## 相似题目



## Links

- [Prev](../utf-8-validation/README.md) 
- [Next](../longest-palindrome/README.md) 

