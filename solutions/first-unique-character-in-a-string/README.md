
# [字符串中的第一个唯一字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string)

## 题目描述

<p>给定一个字符串&nbsp;<code>s</code>&nbsp;，找到 <em>它的第一个不重复的字符，并返回它的索引</em> 。如果不存在，则返回 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> s = "leetcode"
<strong>输出:</strong> 0
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> s = "loveleetcode"
<strong>输出:</strong> 2
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> s = "aabb"
<strong>输出:</strong> -1
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;只包含小写字母</li>
</ul>


## 题解

### cpp [🔗](first-unique-character-in-a-string.cpp) 
```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        int cnt[256] = {0};
        for (auto &c : s) {
            cnt[c] += 1;
        }
        for (int i = 0; i < s.size(); i++) {
            if (cnt[s[i]] == 1) return i;
        }
        return -1;
    }
};
```


## 相关话题

- [队列](../../tags/queue.md) 
- [哈希表](../../tags/hash-table.md) 
- [字符串](../../tags/string.md) 
- [计数](../../tags/counting.md) 


## 相似题目

- [根据字符出现频率排序](../sort-characters-by-frequency/README.md)  [Medium] 


## Links

- [Prev](../lexicographical-numbers/README.md) 
- [Next](../find-the-difference/README.md) 

