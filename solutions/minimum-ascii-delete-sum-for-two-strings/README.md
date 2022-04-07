
# [两个字符串的最小ASCII删除和](https://leetcode-cn.com/problems/minimum-ascii-delete-sum-for-two-strings)

## 题目描述

<p>给定两个字符串<code>s1</code>&nbsp;和&nbsp;<code>s2</code>，返回 <em>使两个字符串相等所需删除字符的&nbsp;<strong>ASCII&nbsp;</strong>值的最小和&nbsp;</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> s1 = "sea", s2 = "eat"
<strong>输出:</strong> 231
<strong>解释:</strong> 在 "sea" 中删除 "s" 并将 "s" 的值(115)加入总和。
在 "eat" 中删除 "t" 并将 116 加入总和。
结束时，两个字符串相等，115 + 116 = 231 就是符合条件的最小和。
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> s1 = "delete", s2 = "leet"
<strong>输出:</strong> 403
<strong>解释:</strong> 在 "delete" 中删除 "dee" 字符串变成 "let"，
将 100[d]+101[e]+101[e] 加入总和。在 "leet" 中删除 "e" 将 101[e] 加入总和。
结束时，两个字符串都等于 "let"，结果即为 100+101+101+101 = 403 。
如果改为将两个字符串转换为 "lee" 或 "eet"，我们会得到 433 或 417 的结果，比答案更大。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>0 &lt;= s1.length, s2.length &lt;= 1000</code></li>
	<li><code>s1</code>&nbsp;和&nbsp;<code>s2</code>&nbsp;由小写英文字母组成</li>
</ul>


## 题解

### cpp [🔗](minimum-ascii-delete-sum-for-two-strings.cpp) 
```cpp
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1));
        
        for (int i = 1; i <= s1.size(); i++) 
            dp[i][0] = s1[i-1] + dp[i-1][0];

        for (int i = 1; i <= s2.size(); i++) 
            dp[0][i] = s2[i-1] + dp[0][i-1];

        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = std::min(s1[i-1] + dp[i-1][j], s2[j-1] + dp[i][j-1]);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
```


## 相关话题

- [字符串](../../tags/string.md) 
- [动态规划](../../tags/dynamic-programming.md) 


## 相似题目

- [编辑距离](../edit-distance/README.md)  [Hard] 
- [两个字符串的删除操作](../delete-operation-for-two-strings/README.md)  [Medium] 


## Links

- [Prev](../count-binary-substrings/README.md) 
- [Next](../max-stack/README.md) 

