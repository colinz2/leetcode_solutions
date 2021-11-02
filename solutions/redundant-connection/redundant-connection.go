// @Title: Redundant Connection
// @Author: realzhangm
// @Date: 2021-11-02T16:47:35+08:00
// @URL: https://leetcode-cn.com/problems/redundant-connection


func findRedundantConnection(edges [][]int) []int {
    p := make([]int, len(edges) + 1)
    for i := 0; i < len(edges) + 1; i++ {
        p[i] = i
    }

    for _, edge := range edges {
        if find(p, edge[0]) ==  find(p , edge[1]) {
            return edge
        }
        union(p, edge[0], edge[1])
    }
    return []int{}
}

func union(p []int, a, b int) {
    p[find(p, a)] = find(p, b)
    p[find(p, b)] = find(p, a)
}

func find(p []int, a int) int {
    if a != p[a] {
        p[a] = find(p, p[a])
    }
    return p[a]
}
