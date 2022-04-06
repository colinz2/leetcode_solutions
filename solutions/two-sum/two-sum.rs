// @Title: Two Sum
// @Author: colinjxc
// @Date: 2022-04-05T03:56:50+08:00
// @URL: https://leetcode-cn.com/problems/two-sum



use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut seen: HashMap<i32 ,i32> = HashMap::new();
        for (i, v) in nums.iter().enumerate() {
            match seen.get(v) {
                Some(index) => {
                    return vec![*index, i as i32];
                }
                None => {
                    seen.insert(target - v, i as i32); 
                }
            }
        }
        vec![]
    }
}
