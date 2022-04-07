
# [相隔为 1 的编辑距离](https://leetcode-cn.com/problems/one-edit-distance)

## 题目描述

<p>给定两个字符串 <code>s</code> 和&nbsp;<code>t</code> ，如果它们的编辑距离为 <code>1</code> ，则返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p>字符串 <code>s</code> 和字符串 <code>t</code> 之间满足编辑距离等于 1 有三种可能的情形：</p>

<ul>
	<li>往 <code>s</code>&nbsp;中插入 <strong>恰好一个</strong> 字符得到 <code>t</code></li>
	<li>从 <code>s</code>&nbsp;中删除 <strong>恰好一个</strong> 字符得到 <code>t</code></li>
	<li>在 <code>s</code>&nbsp;中用 <strong>一个不同的字符</strong> 替换 <strong>恰好一个</strong> 字符得到 <code>t</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入: </strong><strong><em>s</em></strong> = "ab", <strong><em>t</em></strong> = "acb"
<strong>输出: </strong>true
<strong>解释: </strong>可以将 'c' 插入字符串 <strong><em>s</em></strong>&nbsp;来得到 <em><strong>t</strong></em>。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入: </strong><strong><em>s</em></strong> = "cab", <strong><em>t</em></strong> = "ad"
<strong>输出: </strong>false
<strong>解释: </strong>无法通过 1 步操作使 <em><strong>s</strong></em> 变为 <em><strong>t</strong></em>。</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>0 &lt;= s.length, t.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> 和&nbsp;<code>t</code>&nbsp;由小写字母，大写字母和数字组成</li>
</ul>


## 题解

### cpp [🔗](one-edit-distance.cpp) 
```cpp
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        // let len of s > t
        int distance = s.size() - t.size();
        if (distance < 0) {
            return isOneEditDistance(t, s);
        }
        if (distance > 1) {
            return false;
        }

        int len = t.size();
        for (int i = 0; i < len; i++) {
            if (s[i] != t[i]) {
                if (distance > 0) {
                    return s.substr(i+1) == t.substr(i);
                } else {
                    return s.substr(i+1) == t.substr(i+1);
                }
            }
        }
        return distance > 0;
    }
};
```


## 相关话题

- [双指针](https://leetcode-cn.com/tag/two-pointers) 
- [字符串](https://leetcode-cn.com/tag/string) 


## 相似题目

- [编辑距离](../edit-distance/README.md)  [Hard] 


## Links

- [Prev](../intersection-of-two-linked-lists/README.md) 
- [Next](../find-peak-element/README.md) 

