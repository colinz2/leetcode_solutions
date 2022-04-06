// @Title: Climbing Stairs
// @Author: colinjxc
// @Date: 2021-07-07T10:46:09+08:00
// @URL: https://leetcode-cn.com/problems/climbing-stairs


func climbStairs(n int) int {
	t := make([]int, n+2)
	t[1] = 1
	t[2] = 2

	for i := 3; i <= n; i++ {
		t[i] = t[i-1] + t[i-2]
	}
	return t[n]
}

