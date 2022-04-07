
# [](https://leetcode-cn.com/problems/unique-paths-ii)

## 题目描述



## 题解

### cpp [🔗](unique-paths-ii.cpp) 
```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();
        if (!m) return 0;

        int n = obstacleGrid[0].size();
        if (!n || obstacleGrid[0][0])
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = 1;
        for (int j = 1; j < n; j++)
            if (obstacleGrid[0][j])
                dp[0][j] = 0;
            else
                dp[0][j] = dp[0][j - 1];

        for (int i = 1; i < m; i++)
            if (obstacleGrid[i][0])
                dp[i][0] = 0;
            else
                dp[i][0] = dp[i - 1][0];

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (obstacleGrid[i][j])
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m - 1][n - 1];
    }
};

```


## 相关话题



## 相似题目



## Links

- [Prev](../unique-paths/README.md) 
- [Next](../minimum-path-sum/README.md) 

