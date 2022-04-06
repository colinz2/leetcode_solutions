
# [最后一个单词的长度](https://leetcode-cn.com/problems/length-of-last-word)

## 题目描述

<p>给你一个字符串 <code>s</code>，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 <strong>最后一个</strong> 单词的长度。</p>

<p><strong>单词</strong> 是指仅由字母组成、不包含任何空格字符的最大子字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "Hello World"
<strong>输出：</strong>5
<strong>解释：</strong>最后一个单词是“World”，长度为5。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "   fly me   to   the moon  "
<strong>输出：</strong>4<strong>
解释：</strong>最后一个单词是“moon”，长度为4。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "luffy is still joyboy"
<strong>输出：</strong>6
<strong>解释：</strong>最后一个单词是长度为6的“joyboy”。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> 仅有英文字母和空格 <code>' '</code> 组成</li>
	<li><code>s</code> 中至少存在一个单词</li>
</ul>


## 题解

### cpp [🔗](length-of-last-word.cpp) 
```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() < 1) return 0;
        int cnt =0;
        bool _space_end = true;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                _space_end = false;
                cnt++;
            } else if (_space_end) {
                continue;
            } else {
                break;
            }
        }
        return cnt;
    }
};
```


## 相关话题

- [字符串](https://leetcode-cn.com/tag/string) 


## 相似题目



## Links

- [Prev](../merge-intervals/README.md) 
- [Next](../spiral-matrix-ii/README.md) 

