
# [同构字符串](https://leetcode-cn.com/problems/isomorphic-strings)

## 题目描述

<p>给定两个字符串&nbsp;<code>s</code>&nbsp;和&nbsp;<code>t</code>&nbsp;，判断它们是否是同构的。</p>

<p>如果&nbsp;<code>s</code>&nbsp;中的字符可以按某种映射关系替换得到&nbsp;<code>t</code>&nbsp;，那么这两个字符串是同构的。</p>

<p>每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>s = <code>"egg", </code>t = <code>"add"</code>
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = <code>"foo", </code>t = <code>"bar"</code>
<strong>输出：</strong>false</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = <code>"paper", </code>t = <code>"title"</code>
<strong>输出：</strong>true</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<p><meta charset="UTF-8" /></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>t.length == s.length</code></li>
	<li><code>s</code>&nbsp;和&nbsp;<code>t</code>&nbsp;由任意有效的 ASCII 字符组成</li>
</ul>


## 题解

### cpp [🔗](isomorphic-strings.cpp) 
```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int c1[256] = {0};
        int c2[256] = {0};
        
        if (s.size() != t.size()) {
            return false;
        }

        for (int i = 0; i < s.size(); i++) {
            if (c1[s[i]] != c2[t[i]]) {
                return false;
            }
            c1[s[i]] = i + 1;
            c2[t[i]] = i + 1;
        }

        return true;
    }
};
```


## 相关话题

- [哈希表](https://leetcode-cn.com/tag/hash-table) 
- [字符串](https://leetcode-cn.com/tag/string) 


## 相似题目

- [单词规律](../word-pattern/README.md)  [Easy] 


## Links

- [Prev](../count-primes/README.md) 
- [Next](../reverse-linked-list/README.md) 

