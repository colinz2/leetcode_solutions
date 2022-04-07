
# [岛屿数量](https://leetcode-cn.com/problems/number-of-islands)

## 题目描述

<p>给你一个由 <code>'1'</code>（陆地）和 <code>'0'</code>（水）组成的的二维网格，请你计算网格中岛屿的数量。</p>

<p>岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。</p>

<p>此外，你可以假设该网格的四条边均被水包围。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
<strong>输出：</strong>3
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 <= m, n <= 300</code></li>
	<li><code>grid[i][j]</code> 的值为 <code>'0'</code> 或 <code>'1'</code></li>
</ul>


## 题解

### cpp [🔗](number-of-islands.cpp) 
```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid.front().size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int res = 0;

        function<int(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || j < 0 || i == m || j == n) {
                return 0;
            }
            if (vis[i][j] || grid[i][j] == '0') return 0;
            vis[i][j] = true;
            return 1 + dfs(i, j-1) + dfs(i-1,j) + dfs(i+1,j) + dfs(i,j+1);
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    res += (dfs(i, j) > 0);
                }
            }
        }

        return res;
    }
};
```


## 相关话题

- [深度优先搜索](../../tags/depth-first-search.md) 
- [广度优先搜索](../../tags/breadth-first-search.md) 
- [并查集](../../tags/union-find.md) 
- [数组](../../tags/array.md) 
- [矩阵](../../tags/matrix.md) 


## 相似题目

- [被围绕的区域](../surrounded-regions/README.md)  [Medium] 


## Links

- [Prev](../binary-tree-right-side-view/README.md) 
- [Next](../happy-number/README.md) 

