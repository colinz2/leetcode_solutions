// @Title: Fizz Buzz
// @Author: colinjxc
// @Date: 2022-04-04T21:06:15+08:00
// @URL: https://leetcode-cn.com/problems/fizz-buzz


impl Solution {
    pub fn fizz_buzz(n: i32) -> Vec<String> {
        let mut i = 1;
        let mut res = Vec::new();

        while i <= n {
            if i % 15 == 0 {
                res.push("FizzBuzz".to_string());
            } else if (i % 5 == 0) {
                res.push("Buzz".to_string());
            } else if (i % 3 == 0) {
                res.push("Fizz".to_string());
            } else {
                res.push(i.to_string());
            }
            i += 1;
        }
        return res;
    }
}
