// @Title: Redundant Connection
// @Author: colinjxc
// @Date: 2022-01-24T22:51:05+08:00
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
    rootA := find(p, a)
    rootB := find(p, b)
    if rootA != rootB {
        p[rootA] = rootB
    }
}

func find(p []int, a int) int {
    if a != p[a] {
        p[a] = find(p, p[a])
    }
    return p[a]
}
