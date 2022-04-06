// @Title: Binary Prefix Divisible By 5
// @Author: colinjxc
// @Date: 2021-10-27T23:47:08+08:00
// @URL: https://leetcode-cn.com/problems/binary-prefix-divisible-by-5


func prefixesDivBy5(nums []int) []bool {
    ans := make([]bool, len(nums))
    x := 0
    // 如果x为和而不取模，有溢出问题啊！！！
    for i, v := range nums {
        x = (x<<1 | v) % 5
        ans[i] = x == 0
    }
    return ans
}
