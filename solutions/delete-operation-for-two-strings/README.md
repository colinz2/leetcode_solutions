
# [两个字符串的删除操作](https://leetcode-cn.com/problems/delete-operation-for-two-strings)

## 题目描述

<p>给定两个单词&nbsp;<code>word1</code>&nbsp;和<meta charset="UTF-8" />&nbsp;<code>word2</code>&nbsp;，返回使得<meta charset="UTF-8" />&nbsp;<code>word1</code>&nbsp;和&nbsp;<meta charset="UTF-8" />&nbsp;<code>word2</code><em>&nbsp;</em><strong>相同</strong>所需的<strong>最小步数</strong>。</p>

<p><strong>每步&nbsp;</strong>可以删除任意一个字符串中的一个字符。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> word1 = "sea", word2 = "eat"
<strong>输出:</strong> 2
<strong>解释:</strong> 第一步将 "sea" 变为 "ea" ，第二步将 "eat "变为 "ea"
</pre>

<p><strong>示例 &nbsp;2:</strong></p>

<pre>
<b>输入：</b>word1 = "leetcode", word2 = "etco"
<b>输出：</b>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>
<meta charset="UTF-8" />

<ul>
	<li><code>1 &lt;= word1.length, word2.length &lt;= 500</code></li>
	<li><code>word1</code>&nbsp;和&nbsp;<code>word2</code>&nbsp;只包含小写英文字母</li>
</ul>


## 题解

### cpp [🔗](delete-operation-for-two-strings.cpp) 
```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j]
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1));
        for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for (int i = 0; i <= word2.size(); i++) dp[0][i] = i;

        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    int del1 = 1 + dp[i-1][j];
                    int del2 = 1 + dp[i][j-1];
                    dp[i][j] = std::min(del1, del2);
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
```


## 相关话题

- [字符串](https://leetcode-cn.com/tag/string) 
- [动态规划](https://leetcode-cn.com/tag/dynamic-programming) 


## 相似题目

- [编辑距离](../edit-distance/README.md)  [Hard] 
- [两个字符串的最小ASCII删除和](../minimum-ascii-delete-sum-for-two-strings/README.md)  [Medium] 


## Links

- [Prev](../kill-process/README.md) 
- [Next](../valid-square/README.md) 

