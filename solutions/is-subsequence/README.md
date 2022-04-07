
# [判断子序列](https://leetcode-cn.com/problems/is-subsequence)

## 题目描述

<p>给定字符串 <strong>s</strong> 和 <strong>t</strong> ，判断 <strong>s</strong> 是否为 <strong>t</strong> 的子序列。</p>

<p>字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，<code>"ace"</code>是<code>"abcde"</code>的一个子序列，而<code>"aec"</code>不是）。</p>

<p><strong>进阶：</strong></p>

<p>如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？</p>

<p><strong>致谢：</strong></p>

<p>特别感谢<strong> </strong><a href="https://leetcode.com/pbrother/">@pbrother </a>添加此问题并且创建所有测试用例。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "abc", t = "ahbgdc"
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "axc", t = "ahbgdc"
<strong>输出：</strong>false
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= s.length <= 100</code></li>
	<li><code>0 <= t.length <= 10^4</code></li>
	<li>两个字符串都只由小写字符组成。</li>
</ul>


## 题解

### cpp [🔗](is-subsequence.cpp) 
```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index = 0;
        for (auto c : t) {
            if (index < s.size() && c == s[index]) {
                index++;
            }
        }
        return index == s.size();
    }
};
```
### c [🔗](is-subsequence.c) 
```c
bool isSubsequence(char * s, char * t){
    while (*s && *t) s += (*s == *t++);
    return !*s;
}
```
### golang [🔗](is-subsequence.go) 
```golang
func isSubsequence(s string, t string) bool {
    m, n := len(s), len(t)
    dp := make([][]int, m+1)
    for i := 0; i <= m; i++ {
        dp[i] = make([]int, n+1)
    }

    for i := 1; i <= m; i++ {
        for j := 1; j <= n; j++ {
            if s[i-1] == t[j-1] {
                dp[i][j] = dp[i-1][j-1] + 1
            } else {
                dp[i][j] = dp[i][j-1]
            }
        }
    }
    return dp[m][n] == len(s)
}
```


## 相关话题

- [双指针](../../tags/two-pointers.md) 
- [字符串](../../tags/string.md) 
- [动态规划](../../tags/dynamic-programming.md) 


## 相似题目

- [匹配子序列的单词数](../number-of-matching-subsequences/README.md)  [Medium] 


## Links

- [Prev](../find-the-difference/README.md) 
- [Next](../utf-8-validation/README.md) 

