// @Title: Hamming Distance
// @Author: colinjxc
// @Date: 2021-05-21T12:43:08+08:00
// @URL: https://leetcode-cn.com/problems/hamming-distance


func hammingDistance(x int, y int) int {
	res := 0
	z := x ^ y
	for z != 0 {
		if z&1 == 1 {
			res++
		}
		z >>= 1
	}
	return res
}

