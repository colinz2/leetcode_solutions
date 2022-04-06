
# [仅仅反转字母](https://leetcode-cn.com/problems/reverse-only-letters)

## 题目描述

<p>给你一个字符串 <code>s</code> ，根据下述规则反转字符串：</p>

<ul>
	<li>所有非英文字母保留在原有位置。</li>
	<li>所有英文字母（小写或大写）位置反转。</li>
</ul>

<p>返回反转后的 <code>s</code><em> 。</em></p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "ab-cd"
<strong>输出：</strong>"dc-ba"
</pre>

<ol>
</ol>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "a-bC-dEf-ghIj"
<strong>输出：</strong>"j-Ih-gfE-dCba"
</pre>

<ol>
</ol>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "Test1ng-Leet=code-Q!"
<strong>输出：</strong>"Qedo1ct-eeLg=ntse-T!"
</pre>

<p>&nbsp;</p>

<p><strong>提示</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 仅由 ASCII 值在范围 <code>[33, 122]</code> 的字符组成</li>
	<li><code>s</code> 不含 <code>'\"'</code> 或 <code>'\\'</code></li>
</ul>


## 题解

### cpp [🔗](reverse-only-letters.cpp) 
```cpp
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!isalpha(s[i])) {
                i++;
                continue;
            }
            if (!isalpha(s[j])) {
                j--;
                continue;
            }
            std::swap(s[i++], s[j--]);
        }
        return s;
    }
};
```


## 相关话题

- [双指针](https://leetcode-cn.com/tag/two-pointers) 
- [字符串](https://leetcode-cn.com/tag/string) 


## 相似题目



## Links

- [Prev](../sort-array-by-parity/README.md) 
- [Next](../unique-email-addresses/README.md) 

