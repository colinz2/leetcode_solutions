// @Title: Binary Search
// @Author: colinjxc
// @Date: 2021-10-22T09:40:58+08:00
// @URL: https://leetcode-cn.com/problems/binary-search


impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut left = 0;
        let mut right = nums.len();
        while left < right {
            let mid = left + ((right - left) >> 1) ;
            if target == nums[mid] {
                return mid as i32;
            } else if target < nums[mid] {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
}
