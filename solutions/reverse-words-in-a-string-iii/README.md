
# [反转字符串中的单词 III](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii)

## 题目描述

<p>给定一个字符串<meta charset="UTF-8" />&nbsp;<code>s</code>&nbsp;，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "Let's take LeetCode contest"
<strong>输出：</strong>"s'teL ekat edoCteeL tsetnoc"
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入：</strong> s = "God Ding"
<strong>输出：</strong>"doG gniD"
</pre>

<p>&nbsp;</p>

<p><strong><strong><strong><strong>提示：</strong></strong></strong></strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><meta charset="UTF-8" /><code>s</code>&nbsp;包含可打印的 <strong>ASCII</strong> 字符。</li>
	<li><meta charset="UTF-8" /><code>s</code>&nbsp;不包含任何开头或结尾空格。</li>
	<li><meta charset="UTF-8" /><code>s</code>&nbsp;里 <strong>至少</strong> 有一个词。</li>
	<li><meta charset="UTF-8" /><code>s</code>&nbsp;中的所有单词都用一个空格隔开。</li>
</ul>


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

- [双指针](https://leetcode-cn.com/tag/two-pointers) 
- [字符串](https://leetcode-cn.com/tag/string) 


## 相似题目

- [反转字符串 II](../reverse-string-ii/README.md)  [Easy] 


## Links

- [Prev](../student-attendance-record-i/README.md) 
- [Next](../subarray-sum-equals-k/README.md) 

