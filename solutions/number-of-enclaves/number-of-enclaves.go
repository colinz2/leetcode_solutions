// @Title: Number of Enclaves
// @Author: colinjxc
// @Date: 2022-02-12T18:39:46+08:00
// @URL: https://leetcode-cn.com/problems/number-of-enclaves


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
