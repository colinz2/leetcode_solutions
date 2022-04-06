
# [无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters)

## 题目描述

<p>给定一个字符串 <code>s</code> ，请你找出其中不含有重复字符的&nbsp;<strong>最长子串&nbsp;</strong>的长度。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre>
<strong>输入: </strong>s = "abcabcbb"
<strong>输出: </strong>3 
<strong>解释:</strong> 因为无重复字符的最长子串是 <code>"abc"，所以其</code>长度为 3。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入: </strong>s = "bbbbb"
<strong>输出: </strong>1
<strong>解释: </strong>因为无重复字符的最长子串是 <code>"b"</code>，所以其长度为 1。
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入: </strong>s = "pwwkew"
<strong>输出: </strong>3
<strong>解释: </strong>因为无重复字符的最长子串是&nbsp;<code>"wke"</code>，所以其长度为 3。
&nbsp;    请注意，你的答案必须是 <strong>子串 </strong>的长度，<code>"pwke"</code>&nbsp;是一个<em>子序列，</em>不是子串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>s</code>&nbsp;由英文字母、数字、符号和空格组成</li>
</ul>


## 题解

### c [🔗](longest-substring-without-repeating-characters.c) 
```c
int lengthOfLongestSubstring(char * s){
    int left = 0;
    int right = 0;
    int max_len = 0;

    bool exist[256] = {false,};

    while (*(s+right)) {
        if (!exist[*(s+right)]) {
            exist[*(s+right)] = true;
            if (right - left + 1 > max_len) {
                max_len = right - left + 1;
            }
            right++;
        } else {
            exist[*(s+left)] = false;
            left++;
        }
    }
    return max_len;
}
```
### cpp [🔗](longest-substring-without-repeating-characters.cpp) 
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool exists[256] = {false};
        int left = 0, right = 0;
        int max_len = 0;

        while (right < s.size()) {
            int next = s[right];
            if (!exists[next]) {
                exists[s[right]] = true;
                max_len = std::max(max_len, right - left + 1);
                right++;
            } else {
                exists[s[left]] = false;
                left++;
            }
        }
        return max_len;
    }
};
```


## 相关话题

- [哈希表](https://leetcode-cn.com/tag/hash-table) 
- [字符串](https://leetcode-cn.com/tag/string) 
- [滑动窗口](https://leetcode-cn.com/tag/sliding-window) 


## 相似题目



## Links

- [Prev](../add-two-numbers/README.md) 
- [Next](../median-of-two-sorted-arrays/README.md) 

