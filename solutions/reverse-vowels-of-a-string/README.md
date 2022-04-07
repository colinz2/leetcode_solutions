
# [反转字符串中的元音字母](https://leetcode-cn.com/problems/reverse-vowels-of-a-string)

## 题目描述

<p>给你一个字符串 <code>s</code> ，仅反转字符串中的所有元音字母，并返回结果字符串。</p>

<p>元音字母包括 <code>'a'</code>、<code>'e'</code>、<code>'i'</code>、<code>'o'</code>、<code>'u'</code>，且可能以大小写两种形式出现。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "hello"
<strong>输出：</strong>"holle"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "leetcode"
<strong>输出：</strong>"leotcede"</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 3 * 10<sup>5</sup></code></li>
	<li><code>s</code> 由 <strong>可打印的 ASCII</strong> 字符组成</li>
</ul>


## 题解

### cpp [🔗](reverse-vowels-of-a-string.cpp) 
```cpp
class Solution {
public:
    string reverseVowels(string s) {
        int dict[256] = {0};
        dict['a'] = 1, dict['A'] = 1;
        dict['e'] = 1, dict['E'] = 1;
        dict['i'] = 1, dict['I'] = 1;
        dict['o'] = 1, dict['O'] = 1;
        dict['u'] = 1, dict['U'] = 1;
        int start = 0, end = s.size() - 1;
        while (start < end) {
            while (start < end && !dict[s[start]]) start++;
            while (start < end && !dict[s[end]]) end--;
            swap(s[start], s[end]);
            start++;
            end--;
        }
        return s;
    }
};


```


## 相关话题

- [双指针](../../tags/two-pointers.md) 
- [字符串](../../tags/string.md) 


## 相似题目

- [反转字符串](../reverse-string/README.md)  [Easy] 


## Links

- [Prev](../reverse-string/README.md) 
- [Next](../moving-average-from-data-stream/README.md) 

