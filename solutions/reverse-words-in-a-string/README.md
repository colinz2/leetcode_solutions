
# [颠倒字符串中的单词](https://leetcode-cn.com/problems/reverse-words-in-a-string)

## 题目描述

<p>给你一个字符串 <code>s</code> ，颠倒字符串中 <strong>单词</strong> 的顺序。</p>

<p><strong>单词</strong> 是由非空格字符组成的字符串。<code>s</code> 中使用至少一个空格将字符串中的 <strong>单词</strong> 分隔开。</p>

<p>返回 <strong>单词</strong> 顺序颠倒且 <strong>单词</strong> 之间用单个空格连接的结果字符串。</p>

<p><strong>注意：</strong>输入字符串 <code>s</code>中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "<code>the sky is blue</code>"
<strong>输出：</strong>"<code>blue is sky the</code>"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = " &nbsp;hello world &nbsp;"
<strong>输出：</strong>"world hello"
<strong>解释：</strong>颠倒后的字符串中不能存在前导空格和尾随空格。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "a good &nbsp; example"
<strong>输出：</strong>"example good a"
<strong>解释：</strong>如果两个单词间有多余的空格，颠倒后的字符串需要将单词间的空格减少到仅有一个。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> 包含英文大小写字母、数字和空格 <code>' '</code></li>
	<li><code>s</code> 中 <strong>至少存在一个</strong> 单词</li>
</ul>

<ul>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>如果字符串在你使用的编程语言中是一种可变数据类型，请尝试使用&nbsp;<code>O(1)</code> 额外空间复杂度的 <strong>原地</strong> 解法。</p>


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

- [双指针](../../tags/two-pointers.md) 
- [字符串](../../tags/string.md) 


## 相似题目



## Links

- [Prev](../evaluate-reverse-polish-notation/README.md) 
- [Next](../min-stack/README.md) 

