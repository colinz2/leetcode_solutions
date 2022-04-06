// @Title: Number of Provinces
// @Author: colinjxc
// @Date: 2021-10-28T22:03:16+08:00
// @URL: https://leetcode-cn.com/problems/number-of-provinces


func findCircleNum(isConnected [][]int) int {
    pCnt := 0
    vis := make([]bool, len(isConnected))
    
    var dfs func(int)
    dfs = func(from int) {
        vis[from] = true;
        for i, c := range isConnected[from] {
            if c == 1 && !vis[i] {
                dfs(i)
            }
        }
    }

    for i, _:= range isConnected {
        if !vis[i] {
            pCnt++
            dfs(i)
        }
    }
    return pCnt
}
