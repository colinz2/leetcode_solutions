
# [字母异位词分组](https://leetcode-cn.com/problems/group-anagrams)

## 题目描述

<p>给你一个字符串数组，请你将 <strong>字母异位词</strong> 组合在一起。可以按任意顺序返回结果列表。</p>

<p><strong>字母异位词</strong> 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> strs = <code>["eat", "tea", "tan", "ate", "nat", "bat"]</code>
<strong>输出: </strong>[["bat"],["nat","tan"],["ate","eat","tea"]]</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> strs = <code>[""]</code>
<strong>输出: </strong>[[""]]
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> strs = <code>["a"]</code>
<strong>输出: </strong>[["a"]]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= strs.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= strs[i].length &lt;= 100</code></li>
	<li><code>strs[i]</code>&nbsp;仅包含小写字母</li>
</ul>


## 题解

### cpp [🔗](group-anagrams.cpp) 
```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> smap;
        vector<vector<string>> res;
        for (auto &s : strs) {
            string tmp(s);
            sort(tmp.begin(), tmp.end());
            smap[tmp].push_back(s);
        }
        for (auto &m : smap) {
            res.emplace_back(m.second);
        }

        return res;        
    }
};
```


## 相关话题

- [哈希表](https://leetcode-cn.com/tag/hash-table) 
- [字符串](https://leetcode-cn.com/tag/string) 
- [排序](https://leetcode-cn.com/tag/sorting) 


## 相似题目

- [有效的字母异位词](../valid-anagram/README.md)  [Easy] 
- [移位字符串分组](../group-shifted-strings/README.md)  [Medium] 


## Links

- [Prev](../rotate-image/README.md) 
- [Next](../powx-n/README.md) 

