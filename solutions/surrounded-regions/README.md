
# [被围绕的区域](https://leetcode-cn.com/problems/surrounded-regions)

## 题目描述

给你一个 <code>m x n</code> 的矩阵 <code>board</code> ，由若干字符 <code>'X'</code> 和 <code>'O'</code> ，找到所有被 <code>'X'</code> 围绕的区域，并将这些区域里所有的 <code>'O'</code> 用 <code>'X'</code> 填充。
<div class="original__bRMd">
<div>
<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/xogrid.jpg" style="width: 550px; height: 237px;" />
<pre>
<strong>输入：</strong>board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
<strong>输出：</strong>[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
<strong>解释：</strong>被围绕的区间不会存在于边界上，换句话说，任何边界上的 <code>'O'</code> 都不会被填充为 <code>'X'</code>。 任何不在边界上，或不与边界上的 <code>'O'</code> 相连的 <code>'O'</code> 最终都会被填充为 <code>'X'</code>。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>board = [["X"]]
<strong>输出：</strong>[["X"]]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n == board[i].length</code></li>
	<li><code>1 <= m, n <= 200</code></li>
	<li><code>board[i][j]</code> 为 <code>'X'</code> 或 <code>'O'</code></li>
</ul>
</div>
</div>


## 题解

### cpp [🔗](surrounded-regions.cpp) 
```cpp
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board.front().size();
        vector<vector<bool>> visO(m, vector(n, false));
        queue<pair<int,int>> q;

        function<void(int, int)> pushQ = [&](int i, int j) {
            if (i >= 0 && i < m && j >=0 && j < n && board[i][j] == 'O') {
                q.push({i, j});
            }
        };

        for (int i = 0; i < m; i++) {
            pushQ(i, 0), pushQ(i, n-1);
        }
        for (int i = 0; i < n; i++) {
            pushQ(0, i), pushQ(m-1, i);
        }
        
        while (!q.empty()) {
            int i = q.front().first, j = q.front().second; q.pop();
            if (!visO[i][j]) {
                visO[i][j] = true;
                pushQ(i, j-1), pushQ(i-1, j), pushQ(i, j+1), pushQ(i+1, j);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !visO[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
```


## 相关话题

- [深度优先搜索](https://leetcode-cn.com/tag/depth-first-search) 
- [广度优先搜索](https://leetcode-cn.com/tag/breadth-first-search) 
- [并查集](https://leetcode-cn.com/tag/union-find) 
- [数组](https://leetcode-cn.com/tag/array) 
- [矩阵](https://leetcode-cn.com/tag/matrix) 


## 相似题目

- [岛屿数量](../number-of-islands/README.md)  [Medium] 


## Links

- [Prev](../sum-root-to-leaf-numbers/README.md) 
- [Next](../single-number/README.md) 

