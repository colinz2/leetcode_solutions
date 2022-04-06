
# [最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring)

## 题目描述

<p>给你一个字符串 <code>s</code>，找到 <code>s</code> 中最长的回文子串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "babad"
<strong>输出：</strong>"bab"
<strong>解释：</strong>"aba" 同样是符合题意的答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "cbbd"
<strong>输出：</strong>"bb"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> 仅由数字和英文字母组成</li>
</ul>


## 题解

### cpp [🔗](longest-palindromic-substring.cpp) 
```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        int n = s.size(), maxLen = 0, start = 0;
        for (int i = 0; i < n - 1; ++i) {
            searchPalindrome(s, i, i, start, maxLen);
            searchPalindrome(s, i, i + 1, start, maxLen);
        }
        return s.substr(start, maxLen);
    }
    void searchPalindrome(string s, int left, int right, int& start, int& maxLen) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left; ++right;
        }
        if (maxLen < right - left - 1) {
            start = left + 1;
            maxLen = right - left - 1;
        }
    }
};
```


## 相关话题

- [字符串](https://leetcode-cn.com/tag/string) 
- [动态规划](https://leetcode-cn.com/tag/dynamic-programming) 


## 相似题目

- [回文排列](../palindrome-permutation/README.md)  [Easy] 


## Links

- [Prev](../median-of-two-sorted-arrays/README.md) 
- [Next](../reverse-integer/README.md) 

