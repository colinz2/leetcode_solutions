
# [最长回文串](https://leetcode-cn.com/problems/longest-palindrome)

## 题目描述

<p>给定一个包含大写字母和小写字母的字符串<meta charset="UTF-8" />&nbsp;<code>s</code>&nbsp;，返回&nbsp;<em>通过这些字母构造成的 <strong>最长的回文串</strong></em>&nbsp;。</p>

<p>在构造过程中，请注意 <strong>区分大小写</strong> 。比如&nbsp;<code>"Aa"</code>&nbsp;不能当做一个回文字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1: </strong></p>

<pre>
<strong>输入:</strong>s = "abccccdd"
<strong>输出:</strong>7
<strong>解释:</strong>
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong>s = "a"
<strong>输入:</strong>1
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong>s = "bb"
<strong>输入:</strong> 2
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code>&nbsp;只能由小写和/或大写英文字母组成</li>
</ul>


## 题解

### c [🔗](longest-palindrome.c) 
```c
int longestPalindrome(char * s){
    int seen[128] = {0,};
    int strlen = 0;
    while (*s) seen[*s++]++, strlen++;
    int ocnt = 0;
    for (int i = 'a'; i <= 'z'; i++) {
        ocnt += seen[i] % 2;
    }
    for (int i = 'A'; i <= 'Z'; i++) {
        ocnt += seen[i] % 2;
    }
    if (ocnt > 0) ocnt--;
    
    return strlen - ocnt;
}
```
### cpp [🔗](longest-palindrome.cpp) 
```cpp
class Solution {
public:


    int longestPalindrome(string s) {

        int n = s.size();
        if (n == 0) return 0;
        int table[52] = {0};
            
        for (int i = 0; i < n; i++)
        {
            int index = int(s[i] - 'A');
            if (s[i] >= 'a')    index -= 6;
            table[index]++;
        }

        int even = 0;
        int odd = 0;
        for (int i = 0; i < 52; i++)
        {
            even += table[i] / 2 * 2;
            odd += table[i] % 2;     
        }
        
        odd = odd > 0 ? 1: 0;
        return even + odd;
    }
};
```


## 相关话题

- [贪心](https://leetcode-cn.com/tag/greedy) 
- [哈希表](https://leetcode-cn.com/tag/hash-table) 
- [字符串](https://leetcode-cn.com/tag/string) 


## 相似题目

- [回文排列](../palindrome-permutation/README.md)  [Easy] 


## Links

- [Prev](../decode-string/README.md) 
- [Next](../fizz-buzz/README.md) 

