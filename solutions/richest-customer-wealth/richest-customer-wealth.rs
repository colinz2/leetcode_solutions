// @Title: Richest Customer Wealth
// @Author: colinjxc
// @Date: 2021-10-27T21:10:04+08:00
// @URL: https://leetcode-cn.com/problems/richest-customer-wealth


impl Solution {
    pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
        accounts.iter()
            .map(|v|v.iter().sum())
            .max()
            .unwrap()
    }
}
