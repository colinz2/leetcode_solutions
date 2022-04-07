
# [重复的子字符串](https://leetcode-cn.com/problems/repeated-substring-pattern)

## 题目描述

<p>给定一个非空的字符串<meta charset="UTF-8" />&nbsp;<code>s</code>&nbsp;，检查是否可以通过由它的一个子串重复多次构成。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> s = "abab"
<strong>输出:</strong> true
<strong>解释:</strong> 可由子串 "ab" 重复两次构成。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> s = "aba"
<strong>输出:</strong> false
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> s = "abcabcabcabc"
<strong>输出:</strong> true
<strong>解释:</strong> 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<p><meta charset="UTF-8" /></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code>&nbsp;由小写英文字母组成</li>
</ul>


## 题解

### cpp [🔗](repeated-substring-pattern.cpp) 
```cpp
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        string nextStr = str;
        int len = str.length();
        if(len < 1) return false;
        for(int i = 1; i <= len / 2; i++){
            if(len % i == 0){
                nextStr = leftShift(str, i);
                if(nextStr == str) return true;
            }
        }
        return false;
    }
    
    string leftShift(string &str, int l){
        string ret = str.substr(l);
        ret += str.substr(0, l);
        return ret;
    }
};
```


## 相关话题

- [字符串](../../tags/string.md) 
- [字符串匹配](../../tags/string-matching.md) 


## 相似题目

- [实现 strStr()](../implement-strstr/README.md)  [Easy] 


## Links

- [Prev](../assign-cookies/README.md) 
- [Next](../hamming-distance/README.md) 

