
# [最小路径和](https://leetcode-cn.com/problems/minimum-path-sum)

## 题目描述

<p>给定一个包含非负整数的 <code><em>m</em> x <em>n</em></code> 网格 <code>grid</code> ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。</p>

<p><strong>说明：</strong>每次只能向下或者向右移动一步。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/05/minpath.jpg" style="width: 242px; height: 242px;" />
<pre>
<strong>输入：</strong>grid = [[1,3,1],[1,5,1],[4,2,1]]
<strong>输出：</strong>7
<strong>解释：</strong>因为路径 1→3→1→1→1 的总和最小。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[1,2,3],[4,5,6]]
<strong>输出：</strong>12
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 <= m, n <= 200</code></li>
	<li><code>0 <= grid[i][j] <= 100</code></li>
</ul>


## 题解

### cpp [🔗](minimum-path-sum.cpp) 
```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        if (m == 0 || n == 0) {
            return 0;
        }
        
        // 初始化矩阵
        vector<vector<int>> stepSum(m+1, vector<int>(n+1, INT_MAX));
        
        int from = 0;
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= n; k++) {
                if (j != 1 || k != 1) 
                    from = std::min(stepSum[j][k-1], stepSum[j-1][k]);
                stepSum[j][k] = grid[j-1][k-1] + from;
            }
        }

        return stepSum[m][n];
    }
};
```
### java [🔗](minimum-path-sum.java) 
```java
class Solution {
    public int minPathSum(int[][] grid) {
        int width = grid[0].length, high = grid.length;
        if (high == 0 || width == 0) return 0;
        // 初始化
        for (int i = 1; i < high; i++) grid[i][0] += grid[i - 1][0];
        for (int i = 1; i < width; i++) grid[0][i] += grid[0][i - 1];
        for (int i = 1; i < high; i++)
            for (int j = 1; j < width; j++)
                grid[i][j] += Math.min(grid[i - 1][j], grid[i][j - 1]);
        return grid[high - 1][width - 1];
    }
}
```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 
- [动态规划](https://leetcode-cn.com/tag/dynamic-programming) 
- [矩阵](https://leetcode-cn.com/tag/matrix) 


## 相似题目

- [不同路径](../unique-paths/README.md)  [Medium] 


## Links

- [Prev](../unique-paths-ii/README.md) 
- [Next](../plus-one/README.md) 

