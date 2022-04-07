
# [有效的括号](https://leetcode-cn.com/problems/valid-parentheses)

## 题目描述

<p>给定一个只包括 <code>'('</code>，<code>')'</code>，<code>'{'</code>，<code>'}'</code>，<code>'['</code>，<code>']'</code> 的字符串 <code>s</code> ，判断字符串是否有效。</p>

<p>有效字符串需满足：</p>

<ol>
	<li>左括号必须用相同类型的右括号闭合。</li>
	<li>左括号必须以正确的顺序闭合。</li>
</ol>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "()"
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "()[]{}"
<strong>输出：</strong>true
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "(]"
<strong>输出：</strong>false
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>s = "([)]"
<strong>输出：</strong>false
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>s = "{[]}"
<strong>输出：</strong>true</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 10<sup>4</sup></code></li>
	<li><code>s</code> 仅由括号 <code>'()[]{}'</code> 组成</li>
</ul>


## 题解

### cpp [🔗](valid-parentheses.cpp) 
```cpp
class Solution {
public:
    bool isValid(string s) {
        unordered_map<int, int> symbol_map = {
                {'(', 1},
                {')', -1},
                {'[', 2},
                {']', -2},
                {'{', 3},
                {'}', -3},
        };
        stack<int> s_stack;
        for (auto c : s) {
            int v = symbol_map[c];
            if (v > 0) {
                s_stack.push(v);
            } else if (v < 0) {
                if (s_stack.empty() || s_stack.top() != -v) {
                    return false;
                }
                s_stack.pop();
            }
        }
        if (!s_stack.empty()) return false;
        return true;
    }
};
```


## 相关话题

- [栈](../../tags/stack.md) 
- [字符串](../../tags/string.md) 


## 相似题目

- [括号生成](../generate-parentheses/README.md)  [Medium] 


## Links

- [Prev](../remove-nth-node-from-end-of-list/README.md) 
- [Next](../merge-two-sorted-lists/README.md) 

