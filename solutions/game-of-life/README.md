
# [生命游戏](https://leetcode-cn.com/problems/game-of-life)

## 题目描述

<p>根据&nbsp;<a href="https://baike.baidu.com/item/%E7%94%9F%E5%91%BD%E6%B8%B8%E6%88%8F/2926434?fr=aladdin" target="_blank">百度百科</a>&nbsp;，&nbsp;<strong>生命游戏</strong>&nbsp;，简称为 <strong>生命</strong> ，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。</p>

<p>给定一个包含 <code>m × n</code>&nbsp;个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态： <code>1</code> 即为 <strong>活细胞</strong> （live），或 <code>0</code> 即为 <strong>死细胞</strong> （dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：</p>

<ol>
	<li>如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；</li>
	<li>如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；</li>
	<li>如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；</li>
	<li>如果死细胞周围正好有三个活细胞，则该位置死细胞复活；</li>
</ol>

<p>下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。给你 <code>m x n</code> 网格面板 <code>board</code> 的当前状态，返回下一个状态。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/26/grid1.jpg" />
<pre>
<strong>输入：</strong>board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
<strong>输出：</strong>[[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/26/grid2.jpg" />
<pre>
<strong>输入：</strong>board = [[1,1],[1,0]]
<strong>输出：</strong>[[1,1],[1,1]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n == board[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 25</code></li>
	<li><code>board[i][j]</code> 为 <code>0</code> 或 <code>1</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。</li>
	<li>本题中，我们使用二维数组来表示面板。原则上，面板是无限的，但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？</li>
</ul>


## 题解

### cpp [🔗](game-of-life.cpp) 
```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>> &board) {
        int step[][2] = {{1,-1},{1,1},{1,0},{-1,0},{-1,-1},{-1,1},{0,1},{0,-1}};
        int m = board.size();
        int n = m ? board[0].size() : 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live_cnt = 0;
                for (int k = 0; k < sizeof(step)/ sizeof(step[0]); k++) {
                    int new_i = i + step[k][0];
                    int new_j = j + step[k][1];
                    if (new_i >= 0 && new_i < m && new_j >=0 && new_j < n) {
                        int around_p = board[new_i][new_j];
                        if (around_p == 1 || around_p == 2) live_cnt++;
                    }
                }
                if (board[i][j]) {
                    if (live_cnt < 2 || live_cnt > 3) board[i][j] = 2;
                } else {
                    if (live_cnt == 3) board[i][j] = 3;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] > 1)
                    board[i][j] -= 2;
            }
        }
    }
};
```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 
- [矩阵](https://leetcode-cn.com/tag/matrix) 
- [模拟](https://leetcode-cn.com/tag/simulation) 


## 相似题目

- [矩阵置零](../set-matrix-zeroes/README.md)  [Medium] 


## Links

- [Prev](../move-zeroes/README.md) 
- [Next](../word-pattern/README.md) 

