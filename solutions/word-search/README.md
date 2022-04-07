
# [单词搜索](https://leetcode-cn.com/problems/word-search)

## 题目描述

<p>给定一个 <code>m x n</code> 二维字符网格 <code>board</code> 和一个字符串单词 <code>word</code> 。如果 <code>word</code> 存在于网格中，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/word2.jpg" style="width: 322px; height: 242px;" />
<pre>
<strong>输入：</strong>board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/word-1.jpg" style="width: 322px; height: 242px;" />
<pre>
<strong>输入：</strong>board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
<strong>输出：</strong>true
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/15/word3.jpg" style="width: 322px; height: 242px;" />
<pre>
<strong>输入：</strong>board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
<strong>输出：</strong>false
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n = board[i].length</code></li>
	<li><code>1 <= m, n <= 6</code></li>
	<li><code>1 <= word.length <= 15</code></li>
	<li><code>board</code> 和 <code>word</code> 仅由大小写英文字母组成</li>
</ul>

<p> </p>

<p><strong>进阶：</strong>你可以使用搜索剪枝的技术来优化解决方案，使其在 <code>board</code> 更大的情况下可以更快解决问题？</p>


## 题解

### cpp [🔗](word-search.cpp) 
```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 每个点都可以
                if (check(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool check(vector<vector<char>>& board, string& word, int index, int i, int j) {
        if (word.size() == index) {
            return true;
        }
        if (i < 0 || j < 0 || i == board.size() || j == board[0].size()) {
            return false;
        }

        if (word[index] != board[i][j]) {
            return false;
        }
        // 由于不能访问重复路径，过河拆桥
        board[i][j] = 0;
        bool res = check(board, word, index+1, i+1, j) ||
                   check(board, word, index+1, i, j+1) ||
                   check(board, word, index+1, i-1, j) ||
                   check(board, word, index+1, i, j-1);      
        board[i][j] = word[index];
        return res;
    }
};
```
### python3 [🔗](word-search.py) 
```python3
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n, word_len = len(board), len(board[0]), len(word)
        def dfs(i, j, k):
            if k == word_len:
                return True
            if not 0 <= i < m or not 0 <= j < n:
                return False
                
            if word[k] != board[i][j]:
                return False
            board[i][j] = '*'

            res = dfs(i-1, j, k+1) or dfs(i+1, j, k+1) or dfs(i, j-1, k+1) or dfs(i, j+1, k+1)
            board[i][j] = word[k]
            return res
            
        for i in range(m):
            for j in range(n):
                if dfs(i, j, 0):
                    return True
        return False
```


## 相关话题

- [数组](../../tags/array.md) 
- [回溯](../../tags/backtracking.md) 
- [矩阵](../../tags/matrix.md) 


## 相似题目



## Links

- [Prev](../subsets/README.md) 
- [Next](../remove-duplicates-from-sorted-array-ii/README.md) 

