
# [验证回文串](https://leetcode-cn.com/problems/valid-palindrome)

## 题目描述

<p>给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。</p>

<p><strong>说明：</strong>本题中，我们将空字符串定义为有效的回文串。</p>

<p> </p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> "A man, a plan, a canal: Panama"
<strong>输出:</strong> true
<strong>解释：</strong>"amanaplanacanalpanama" 是回文串
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> "race a car"
<strong>输出:</strong> false
<strong>解释：</strong>"raceacar" 不是回文串
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 2 * 10<sup>5</sup></code></li>
	<li>字符串 <code>s</code> 由 ASCII 字符组成</li>
</ul>


## 题解

### cpp [🔗](valid-palindrome.cpp) 
```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (!isalnum(s[l])) {
                l++;
                continue;
            }

            if (!isalnum(s[r])) {
                r--;
                continue;
            }

            if (toupper(s[l]) != toupper(s[r])) {
                return false;
            }
            
            l++;
            r--;
        }
        return true;
    }
};
```


## 相关话题

- [双指针](https://leetcode-cn.com/tag/two-pointers) 
- [字符串](https://leetcode-cn.com/tag/string) 


## 相似题目

- [回文链表](../palindrome-linked-list/README.md)  [Easy] 


## Links

- [Prev](../binary-tree-maximum-path-sum/README.md) 
- [Next](../longest-consecutive-sequence/README.md) 

