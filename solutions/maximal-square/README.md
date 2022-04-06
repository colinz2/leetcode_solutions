
# [最大正方形](https://leetcode-cn.com/problems/maximal-square)

## 题目描述

<p>在一个由 <code>'0'</code> 和 <code>'1'</code> 组成的二维矩阵内，找到只包含 <code>'1'</code> 的最大正方形，并返回其面积。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/26/max1grid.jpg" style="width: 400px; height: 319px;" />
<pre>
<strong>输入：</strong>matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
<strong>输出：</strong>4
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/26/max2grid.jpg" style="width: 165px; height: 165px;" />
<pre>
<strong>输入：</strong>matrix = [["0","1"],["1","0"]]
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>matrix = [["0"]]
<strong>输出：</strong>0
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 <= m, n <= 300</code></li>
	<li><code>matrix[i][j]</code> 为 <code>'0'</code> 或 <code>'1'</code></li>
</ul>


## 题解

### c [🔗](maximal-square.c) 
```c
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int min(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}

int min3(int a, int b, int c) {
    return min(min(a, b), c);
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    int* dp[matrixSize];
    for (int i = 0; i < matrixSize; i++) {
        dp[i] = (int*)malloc(sizeof(int)*(matrixColSize[0]));
    }
    int maxWidth = 0;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min3(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1;
                } 
                maxWidth = max(maxWidth, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        free(dp[i]);
    }
    return maxWidth * maxWidth;
}
```
### cpp [🔗](maximal-square.cpp) 
```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix.back().size();
        int res = 0;
        vector<vector<int>> dp(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = std::min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
                    }
                    res = std::max(res, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return res * res;
    }
};
```
### golang [🔗](maximal-square.go) 
```golang
func maximalSquare(matrix [][]byte) int {
    m, n := len(matrix), len(matrix[0])
    max_width := 0
    dp := make([][]int, m)
    for i := 0; i < m; i++ {
        dp[i] = make([]int, n)
    }
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if matrix[i][j] == '1' {
                if i == 0 || j == 0 {
                    dp[i][j] = 1        
                } else {
                    dp[i][j] = min3(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
                }
                max_width = max(max_width, dp[i][j])
            }
        }
    }
    return max_width*max_width
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func min(a, b int) int {
    if a > b {
        return b
    }
    return a
} 

func min3(a, b, c int) int {
    res := min(a, b)
    res = min(res, c)
    return res
}
```
### python3 [🔗](maximal-square.py) 
```python3
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        m = len(matrix)
        n = len(matrix[0])
        max_width =  0
        dp = [[0]*n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == '1':
                    if i == 0 or j == 0:
                        dp[i][j] = 1
                    else: 
                        dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
                    max_width = max(max_width, dp[i][j])
                else:
                    dp[i][j] = 0
        return max_width * max_width
```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 
- [动态规划](https://leetcode-cn.com/tag/dynamic-programming) 
- [矩阵](https://leetcode-cn.com/tag/matrix) 


## 相似题目



## Links

- [Prev](../contains-duplicate-ii/README.md) 
- [Next](../implement-stack-using-queues/README.md) 

