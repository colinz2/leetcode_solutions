// @Title: Richest Customer Wealth
// @Author: colinjxc
// @Date: 2021-10-27T22:23:43+08:00
// @URL: https://leetcode-cn.com/problems/richest-customer-wealth


func maximumWealth(accounts [][]int) int {
    // 原地操作
    for i := 0; i < len(accounts); i++ {
        for j := 1; j < len(accounts[0]); j++ {
            accounts[i][0] += accounts[i][j]
        }
        if accounts[0][0] < accounts[i][0] {
            accounts[0][0] = accounts[i][0]
        }
    }
    return accounts[0][0]
}
