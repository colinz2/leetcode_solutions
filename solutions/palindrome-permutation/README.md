
# [回文排列](https://leetcode-cn.com/problems/palindrome-permutation)

## 题目描述

<p>给定一个字符串，判断该字符串中是否可以通过重新排列组合，形成一个回文字符串。</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入:</strong> <code>&quot;code&quot;</code>
<strong>输出:</strong> false</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入:</strong> <code>&quot;aab&quot;</code>
<strong>输出:</strong> true</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入:</strong> <code>&quot;carerac&quot;</code>
<strong>输出:</strong> true</pre>


## 题解

### c [🔗](palindrome-permutation.c) 
```c
bool canPermutePalindrome(char * s){
    int seen[128] = {0,};
    while (*s) seen[*s++]++;

    int cnt = 0;
    for (int i = 0; i < sizeof(seen)/sizeof(seen[0]); i++) {
        cnt += seen[i] % 2;
        if (cnt > 1) return false;
    } 
    return true;
}
```
### cpp [🔗](palindrome-permutation.cpp) 
```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, int> smap;
        for (auto& c : s) {
            smap[c]++;
        }
        int ocnt = 0;
        for (auto& p : smap) {
            ocnt += p.second % 2;
            if (ocnt > 1) {
                return false;
            }
        }
        return true;
    }
};
```
### python3 [🔗](palindrome-permutation.py) 
```python3
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        seen = collections.defaultdict(int)
        for c in s:
            seen[c] += 1
        cnt = 0
        for v in seen.values():
            cnt += v % 2
            if cnt > 1:
                return False
        return True
```


## 相关话题

- [位运算](../../tags/bit-manipulation.md) 
- [哈希表](../../tags/hash-table.md) 
- [字符串](../../tags/string.md) 


## 相似题目

- [最长回文子串](../longest-palindromic-substring/README.md)  [Medium] 
- [有效的字母异位词](../valid-anagram/README.md)  [Easy] 
- [最长回文串](../longest-palindrome/README.md)  [Easy] 


## Links

- [Prev](../ugly-number-ii/README.md) 
- [Next](../missing-number/README.md) 

