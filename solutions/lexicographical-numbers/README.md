
# [字典序排数](https://leetcode-cn.com/problems/lexicographical-numbers)

## 题目描述

<p>给你一个整数 <code>n</code> ，按字典序返回范围 <code>[1, n]</code> 内所有整数。</p>

<p>你必须设计一个时间复杂度为 <code>O(n)</code> 且使用 <code>O(1)</code> 额外空间的算法。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 13
<strong>输出：</strong>[1,10,11,12,13,2,3,4,5,6,7,8,9]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>[1,2]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
</ul>


## 题解

### cpp [🔗](lexicographical-numbers.cpp) 
```cpp
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i <= 9; i++) {
            dfs(i, n, res);
        }
        return res;
    }

    void dfs(int curr, int n, vector<int>& res) {
        if (curr > n) return;
        res.push_back(curr);
        for (int i = 0; i <= 9; i++) {
            dfs(curr*10 + i, n, res);
        }
    }
};
```


## 相关话题

- [深度优先搜索](../../tags/depth-first-search.md) 
- [字典树](../../tags/trie.md) 


## 相似题目



## Links

- [Prev](../ransom-note/README.md) 
- [Next](../first-unique-character-in-a-string/README.md) 

