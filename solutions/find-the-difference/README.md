
# [找不同](https://leetcode-cn.com/problems/find-the-difference)

## 题目描述

<p>给定两个字符串 <code>s</code> 和 <code>t</code>&nbsp;，它们只包含小写字母。</p>

<p>字符串 <code>t</code>&nbsp;由字符串 <code>s</code> 随机重排，然后在随机位置添加一个字母。</p>

<p>请找出在 <code>t</code>&nbsp;中被添加的字母。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "abcd", t = "abcde"
<strong>输出：</strong>"e"
<strong>解释：</strong>'e' 是那个被添加的字母。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "", t = "y"
<strong>输出：</strong>"y"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 1000</code></li>
	<li><code>t.length == s.length + 1</code></li>
	<li><code>s</code> 和 <code>t</code> 只包含小写字母</li>
</ul>


## 题解

### cpp [🔗](find-the-difference.cpp) 
```cpp
class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = 0;
        // or s + t
        for (int i = 0; i < s.size(); i++) {
            c ^= s[i] ^ t[i]; 
        }
        return t.back() ^ c;
    }
};
```


## 相关话题

- [位运算](../../tags/bit-manipulation.md) 
- [哈希表](../../tags/hash-table.md) 
- [字符串](../../tags/string.md) 
- [排序](../../tags/sorting.md) 


## 相似题目

- [只出现一次的数字](../single-number/README.md)  [Easy] 


## Links

- [Prev](../first-unique-character-in-a-string/README.md) 
- [Next](../is-subsequence/README.md) 

