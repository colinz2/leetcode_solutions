
# [飞地的数量](https://leetcode-cn.com/problems/number-of-enclaves)

## 题目描述

<p>给你一个大小为 <code>m x n</code> 的二进制矩阵 <code>grid</code> ，其中 <code>0</code> 表示一个海洋单元格、<code>1</code> 表示一个陆地单元格。</p>

<p>一次 <strong>移动</strong> 是指从一个陆地单元格走到另一个相邻（<strong>上、下、左、右</strong>）的陆地单元格或跨过 <code>grid</code> 的边界。</p>

<p>返回网格中<strong> 无法 </strong>在任意次数的移动中离开网格边界的陆地单元格的数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/18/enclaves1.jpg" style="height: 200px; width: 200px;" />
<pre>
<strong>输入：</strong>grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
<strong>输出：</strong>3
<strong>解释：</strong>有三个 1 被 0 包围。一个 1 没有被包围，因为它在边界上。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/18/enclaves2.jpg" style="height: 200px; width: 200px;" />
<pre>
<strong>输入：</strong>grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
<strong>输出：</strong>0
<strong>解释：</strong>所有 1 都在边界上或可以到达边界。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>grid[i][j]</code> 的值为 <code>0</code> 或 <code>1</code></li>
</ul>


## 题解

### c [🔗](number-of-enclaves.c) 
```c
void dfs(int** grid, int gridSize, int ColSize, int i, int j, int *res) {
  if (i < 0 || i == gridSize || j < 0 || j == ColSize || grid[i][j] == 0) {
    return;
  }
  *res = *res -1;
  grid[i][j] = 0;
  dfs(grid, gridSize, ColSize, i, j - 1, res);
  dfs(grid, gridSize, ColSize, i - 1, j, res);
  dfs(grid, gridSize, ColSize, i, j + 1, res);
  dfs(grid, gridSize, ColSize, i + 1, j, res);
}

int numEnclaves(int** grid, int gridSize, int* gridColSize){
  int cnt1 = 0;
  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < gridColSize[0]; j++) {
      cnt1 += grid[i][j];
    }
  }

  for (int i = 0; i < gridColSize[0]; i++) {
    dfs(grid, gridSize, gridColSize[0], 0, i, &cnt1);
    dfs(grid, gridSize, gridColSize[0], gridSize - 1, i, &cnt1);
  }

  for (int i = 0; i < gridSize; i++) {
    dfs(grid, gridSize, gridColSize[0], i, 0, &cnt1);
    dfs(grid, gridSize, gridColSize[0], i, gridColSize[0] - 1, &cnt1);
  }

  return cnt1;
}
```
### cpp [🔗](number-of-enclaves.cpp) 
```cpp
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
      int cnt = 0, m = grid.size(), n = grid.front().size();
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          cnt += grid[i][j];
        }
      }

      function<void(int,int)> dfsSubtract = [&](int i, int j) {
        if (i < 0 || j < 0 || i == m || j == n || grid[i][j] == 0) {
          return;
        }
        grid[i][j] = 0;
        cnt--;
        dfsSubtract(i, j-1);
        dfsSubtract(i-1, j);
        dfsSubtract(i, j+1);
        dfsSubtract(i+1, j);
      };

      for (int i = 0; i < m; i++) {
        dfsSubtract(i, 0);
        dfsSubtract(i, n-1);
      }

      for (int i = 0; i < n; i++) {
        dfsSubtract(0, i);
        dfsSubtract(m - 1, i);
      }
      return cnt;
    }
};
```
### golang [🔗](number-of-enclaves.go) 
```golang
func numEnclaves(grid [][]int) int {
    m, n := len(grid), len(grid[0])
    cnt1 := 0
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            cnt1 += grid[i][j]
        }
    }
    var dfs func (int, int)
    dfs = func(i, j int) {
        if i < 0 || j < 0 || i == m || j == n || grid[i][j] == 0 {
            return
        }
        grid[i][j] = 0
        cnt1--
        dfs(i, j - 1)
        dfs(i - 1, j)
        dfs(i, j + 1)
        dfs(i + 1, j)
    }

    for i := 0; i < m; i++ {
        dfs(i, 0)
        dfs(i, n - 1)
    }

    for i := 0; i < n; i++ {
        dfs(0, i)
        dfs(m - 1, i)
    }
    return cnt1;
}
```


## 相关话题

- [深度优先搜索](https://leetcode-cn.com/tag/depth-first-search) 
- [广度优先搜索](https://leetcode-cn.com/tag/breadth-first-search) 
- [并查集](https://leetcode-cn.com/tag/union-find) 
- [数组](https://leetcode-cn.com/tag/array) 
- [矩阵](https://leetcode-cn.com/tag/matrix) 


## 相似题目



## Links

- [Prev](../binary-prefix-divisible-by-5/README.md) 
- [Next](../video-stitching/README.md) 

