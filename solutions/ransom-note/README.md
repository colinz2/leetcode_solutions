
# [赎金信](https://leetcode-cn.com/problems/ransom-note)

## 题目描述

<p>给你两个字符串：<code>ransomNote</code> 和 <code>magazine</code> ，判断 <code>ransomNote</code> 能不能由 <code>magazine</code> 里面的字符构成。</p>

<p>如果可以，返回 <code>true</code> ；否则返回 <code>false</code> 。</p>

<p><code>magazine</code> 中的每个字符只能在 <code>ransomNote</code> 中使用一次。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>ransomNote = "a", magazine = "b"
<strong>输出：</strong>false
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>ransomNote = "aa", magazine = "ab"
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>ransomNote = "aa", magazine = "aab"
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= ransomNote.length, magazine.length &lt;= 10<sup>5</sup></code></li>
	<li><code>ransomNote</code> 和 <code>magazine</code> 由小写英文字母组成</li>
</ul>


## 题解

### cpp [🔗](ransom-note.cpp) 
```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> cmap;
        for (auto c : magazine) {
            cmap[c]++;
        }
        for (auto c : ransomNote) {
            auto it = cmap.find(c);
            if (it == cmap.end() || it->second == 0) {
                return false;
            }
            it->second--;
        }
        return true;
    }
};
```


## 相关话题

- [哈希表](../../tags/hash-table.md) 
- [字符串](../../tags/string.md) 
- [计数](../../tags/counting.md) 


## 相似题目



## Links

- [Prev](../linked-list-random-node/README.md) 
- [Next](../lexicographical-numbers/README.md) 

