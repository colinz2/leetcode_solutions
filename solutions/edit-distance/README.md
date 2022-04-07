
# [编辑距离](https://leetcode-cn.com/problems/edit-distance)

## 题目描述

<p>给你两个单词&nbsp;<code>word1</code> 和&nbsp;<code>word2</code>， <em>请返回将&nbsp;<code>word1</code>&nbsp;转换成&nbsp;<code>word2</code> 所使用的最少操作数</em> &nbsp;。</p>

<p>你可以对一个单词进行如下三种操作：</p>

<ul>
	<li>插入一个字符</li>
	<li>删除一个字符</li>
	<li>替换一个字符</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>word1 = "horse", word2 = "ros"
<strong>输出：</strong>3
<strong>解释：</strong>
horse -&gt; rorse (将 'h' 替换为 'r')
rorse -&gt; rose (删除 'r')
rose -&gt; ros (删除 'e')
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>word1 = "intention", word2 = "execution"
<strong>输出：</strong>5
<strong>解释：</strong>
intention -&gt; inention (删除 't')
inention -&gt; enention (将 'i' 替换为 'e')
enention -&gt; exention (将 'n' 替换为 'x')
exention -&gt; exection (将 'n' 替换为 'c')
exection -&gt; execution (插入 'u')
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= word1.length, word2.length &lt;= 500</code></li>
	<li><code>word1</code> 和 <code>word2</code> 由小写英文字母组成</li>
</ul>


## 题解

### cpp [🔗](edit-distance.cpp) 
```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.size(), vector<int>(word2.size())); 
        return edit(word1, 0, word2, 0, memo); 
    }

    int edit(string& w1, int i, string& w2, int j, vector<vector<int>>& memo) {
        if (i == w1.size()) 
            return w2.size() - j;
        if (j == w2.size()) 
            return w1.size() - i;
        
        // 如果当前相等，没有错误，就编辑下个字符
        if (w1[i] == w2[j]) {
            return edit(w1, i+1, w2, j+1, memo);
        }

        // 如果有记忆就算了
        if (memo[i][j] > 0) {
            return memo[i][j];
        }

        int ins = edit(w1, i, w2, j+1, memo);   // 插入 w2[j] -> w1[i]
        int del = edit(w1, i+1, w2, j, memo);   // 删除 wi[i]
        int sub = edit(w1, i+1, w2, j+1, memo); // 替换 wi[i] <-> w2[j]
        memo[i][j] = std::min({ins, del, sub}) + 1;  // 错误增加
        return memo[i][j];
    }
};
```
### golang [🔗](edit-distance.go) 
```golang
func minDistance(word1 string, word2 string) int {
    memo := make([][]int, len(word1) + 1)
    for i := 0; i < len(memo); i++ {
        memo[i] = make([]int, len(word2) + 1)
    }
    return edit(word1, word2, memo)
}

// 编辑剩下的字符串
// 增加记忆化
func edit(w1 string, w2 string, memo [][]int) int {
    if len(w1) == 0 || len(w2) == 0 {
        return len(w2) + len(w1)
    }

    if w1[0] == w2[0] {
        return edit(w1[1:], w2[1:], memo)
    } 

    if memo[len(w1)][len(w2)] != 0 {
        return memo[len(w1)][len(w2)]
    }

    del := 1 + edit(w1[1:], w2[:], memo)
    add := 1 + edit(w1[:], w2[1:], memo)
    sub := 1 + edit(w1[1:], w2[1:], memo)
    memo[len(w1)][len(w2)] = min(del, add, sub)
    return memo[len(w1)][len(w2)]
}

func min(a, b, c int) int {
    if a < b {
        if a < c {
            return a
        } else {
            return c
        }
    } else if (b < c) {
        return b
    } 
    return c
} 
```


## 相关话题

- [字符串](../../tags/string.md) 
- [动态规划](../../tags/dynamic-programming.md) 


## 相似题目

- [相隔为 1 的编辑距离](../one-edit-distance/README.md)  [Medium] 
- [两个字符串的删除操作](../delete-operation-for-two-strings/README.md)  [Medium] 
- [两个字符串的最小ASCII删除和](../minimum-ascii-delete-sum-for-two-strings/README.md)  [Medium] 


## Links

- [Prev](../simplify-path/README.md) 
- [Next](../set-matrix-zeroes/README.md) 

