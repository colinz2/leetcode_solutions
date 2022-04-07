
# [](https://leetcode-cn.com/problems/minimum-path-sum)

## 题目描述



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



## 相似题目



## Links

- [Prev](../unique-paths-ii/README.md) 
- [Next](../plus-one/README.md) 

