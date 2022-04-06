
# [单词拆分](https://leetcode-cn.com/problems/word-break)

## 题目描述

<p>给你一个字符串 <code>s</code> 和一个字符串列表 <code>wordDict</code> 作为字典。请你判断是否可以利用字典中出现的单词拼接出 <code>s</code> 。</p>

<p><strong>注意：</strong>不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> s = "leetcode", wordDict = ["leet", "code"]
<strong>输出:</strong> true
<strong>解释:</strong> 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入:</strong> s = "applepenapple", wordDict = ["apple", "pen"]
<strong>输出:</strong> true
<strong>解释:</strong> 返回 true 因为 <code>"</code>applepenapple<code>"</code> 可以由 <code>"</code>apple" "pen" "apple<code>" 拼接成</code>。
&nbsp;    注意，你可以重复使用字典中的单词。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入:</strong> s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
<strong>输出:</strong> false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 300</code></li>
	<li><code>1 &lt;= wordDict.length &lt;= 1000</code></li>
	<li><code>1 &lt;= wordDict[i].length &lt;= 20</code></li>
	<li><code>s</code> 和 <code>wordDict[i]</code> 仅有小写英文字母组成</li>
	<li><code>wordDict</code> 中的所有字符串 <strong>互不相同</strong></li>
</ul>


## 题解

### cpp [🔗](word-break.cpp) 
```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return false;
        vector<bool> dp(s.size(), false);
        dp[0] = true;

        for(int i = 1; i <= s.size(); i++) {
            for (auto &word : wordDict) {
                auto wordLen = word.size();
                if (i >= wordLen && word == s.substr(i-wordLen, wordLen))
                    dp[i] = dp[i] || dp[i - wordLen];
            }
        }
        return dp[s.size()];
    }
};
```


## 相关话题

- [字典树](https://leetcode-cn.com/tag/trie) 
- [记忆化搜索](https://leetcode-cn.com/tag/memoization) 
- [哈希表](https://leetcode-cn.com/tag/hash-table) 
- [字符串](https://leetcode-cn.com/tag/string) 
- [动态规划](https://leetcode-cn.com/tag/dynamic-programming) 


## 相似题目



## Links

- [Prev](../copy-list-with-random-pointer/README.md) 
- [Next](../linked-list-cycle/README.md) 

