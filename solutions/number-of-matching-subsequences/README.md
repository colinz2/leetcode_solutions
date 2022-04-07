
# [匹配子序列的单词数](https://leetcode-cn.com/problems/number-of-matching-subsequences)

## 题目描述

<p>给定字符串 <code>s</code>&nbsp;和字符串数组&nbsp;<code>words</code>, 返回&nbsp;&nbsp;<em><code>words[i]</code>&nbsp;中是<code>s</code>的子序列的单词个数</em>&nbsp;。</p>

<p>字符串的 <strong>子序列</strong> 是从原始字符串中生成的新字符串，可以从中删去一些字符(可以是none)，而不改变其余字符的相对顺序。</p>

<ul>
	<li>例如， <code>“ace”</code> 是 <code>“abcde”</code> 的子序列。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> s = "abcde", words = ["a","bb","acd","ace"]
<strong>输出:</strong> 3
<strong>解释:</strong> 有三个是&nbsp;s 的子序列的单词: "a", "acd", "ace"。
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>输入: </strong>s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
<strong>输出:</strong> 2
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= words.length &lt;= 5000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 50</code></li>
	<li><code>words[i]</code>和 <font color="#c7254e" face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size: 12.6px; background-color: rgb(249, 242, 244);">s</span></font>&nbsp;都只由小写字母组成。</li>
</ul>
<span style="display:block"><span style="height:0px"><span style="position:absolute">​​​​</span></span></span>

## 题解

### cpp [🔗](number-of-matching-subsequences.cpp) 
```cpp
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        if (words.size() == 0 || s.size() == 0) return 0;
        vector<vector<pair<int, int>>> w(128);
        for (int i = 0; i < words.size(); i++) {
            auto &word = words[i];
            w[word.front()].push_back({i, 0});
        }

        int cnt = 0;
        vector<pair<int, int>> tmp;
        for (auto c : s) {
            tmp.clear();
            tmp.swap(w[c]);

            for (auto &p : tmp) {
                size_t indexInWords = p.first;
                size_t indexOfWord = p.second + 1;
                if (indexOfWord != words[indexInWords].size()) {
                    w[words[indexInWords][indexOfWord]].push_back({indexInWords, indexOfWord});
                } else {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
```


## 相关话题

- [字典树](../../tags/trie.md) 
- [哈希表](../../tags/hash-table.md) 
- [字符串](../../tags/string.md) 
- [排序](../../tags/sorting.md) 


## 相似题目

- [判断子序列](../is-subsequence/README.md)  [Easy] 


## Links

- [Prev](../rotated-digits/README.md) 
- [Next](../rotate-string/README.md) 

