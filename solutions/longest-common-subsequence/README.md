
# [最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence)

## 题目描述

<p>给定两个字符串 <code>text1</code> 和 <code>text2</code>，返回这两个字符串的最长 <strong>公共子序列</strong> 的长度。如果不存在 <strong>公共子序列</strong> ，返回 <code>0</code> 。</p>

<p>一个字符串的 <strong>子序列</strong><em> </em>是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。</p>

<ul>
	<li>例如，<code>"ace"</code> 是 <code>"abcde"</code> 的子序列，但 <code>"aec"</code> 不是 <code>"abcde"</code> 的子序列。</li>
</ul>

<p>两个字符串的 <strong>公共子序列</strong> 是这两个字符串所共同拥有的子序列。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>text1 = "abcde", text2 = "ace" 
<strong>输出：</strong>3  
<strong>解释：</strong>最长公共子序列是 "ace" ，它的长度为 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>text1 = "abc", text2 = "abc"
<strong>输出：</strong>3
<strong>解释：</strong>最长公共子序列是 "abc" ，它的长度为 3 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>text1 = "abc", text2 = "def"
<strong>输出：</strong>0
<strong>解释：</strong>两个字符串没有公共子序列，返回 0 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= text1.length, text2.length <= 1000</code></li>
	<li><code>text1</code> 和 <code>text2</code> 仅由小写英文字符组成。</li>
</ul>


## 题解

### cpp [🔗](longest-common-subsequence.cpp) 
```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1));
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        return dp.back().back();
    }
};
```
### golang [🔗](longest-common-subsequence.go) 
```golang
func longestCommonSubsequence(text1 string, text2 string) int {
    memo := make([][]int, len(text1) + 1)
    for i := 0; i < len(memo); i++ {
        memo[i] = make([]int, len(text2) + 1)
    }
    return getLcs(text1, text2, memo)
}

func getLcs(t1, t2 string, memo [][]int) int {
    len1, len2 := len(t1), len(t2)
    if len1 == 0 || len2 == 0 {
        return 0;
    }

    if memo[len1][len2] > 0 {
        return memo[len1][len2]
    }

    if t1[0] == t2[0] {
        return 1 + getLcs(t1[1:], t2[1:], memo)
    }
    
    memo[len1][len2] = max(getLcs(t1, t2[1:], memo), getLcs(t1[1:], t2, memo))
    return memo[len1][len2]
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```


## 相关话题

- [字符串](https://leetcode-cn.com/tag/string) 
- [动态规划](https://leetcode-cn.com/tag/dynamic-programming) 


## 相似题目



## Links

- [Prev](../decompress-run-length-encoded-list/README.md) 
- [Next](../maximum-number-of-balloons/README.md) 

