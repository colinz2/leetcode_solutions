
# [检测大写字母](https://leetcode-cn.com/problems/detect-capital)

## 题目描述

<p>我们定义，在以下情况时，单词的大写用法是正确的：</p>

<ul>
	<li>全部字母都是大写，比如 <code>"USA"</code> 。</li>
	<li>单词中所有字母都不是大写，比如 <code>"leetcode"</code> 。</li>
	<li>如果单词不只含有一个字母，只有首字母大写，&nbsp;比如&nbsp;<code>"Google"</code> 。</li>
</ul>

<p>给你一个字符串 <code>word</code> 。如果大写用法正确，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>word = "USA"
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>word = "FlaG"
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 100</code></li>
	<li><code>word</code> 由小写和大写英文字母组成</li>
</ul>


## 题解

### cpp [🔗](detect-capital.cpp) 
```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool all_lower = false, all_upper = false, first_upper = false;
        if (isupper(word[0])) {
            all_upper = true;
            first_upper = true;
        } else if (islower(word[0])) {
            all_lower = true;
        }

        for (int i = 1; i < word.size(); i++) {
            int c = word[i];
            if (isupper(c)) {
                all_upper = all_upper & true;
                all_lower = all_lower & false;
                first_upper = first_upper & false;
            } else if (islower(c)) {
                all_upper = all_upper & false;
                all_lower = all_lower & true;
                first_upper = first_upper & true;
            } else {
                all_upper = all_upper & false;
                all_lower = all_lower & false;
                first_upper = first_upper & false;
            }
        }

        return all_lower || all_upper || first_upper;
    }
};
```


## 相关话题

- [字符串](../../tags/string.md) 


## 相似题目



## Links

- [Prev](../next-greater-element-i/README.md) 
- [Next](../continuous-subarray-sum/README.md) 

