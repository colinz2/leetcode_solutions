// @Title: Counting Bits
// @Author: colinjxc
// @Date: 2021-07-17T23:28:22+08:00
// @URL: https://leetcode-cn.com/problems/counting-bits


func countBits(n int) []int {
    res := []int{}
    for i := 0; i < n+1 ; i++ {
        res = append(res, bitCount(i))
    }
    return res
}

func bitCount(n int) int {
    cnt := 0
    for n > 0 {
        n &= (n - 1)
        cnt++
    }
    return cnt
}
