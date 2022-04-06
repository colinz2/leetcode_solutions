// @Title: Two Sum II - Input Array Is Sorted
// @Author: colinjxc
// @Date: 2018-12-19T20:27:40+08:00
// @URL: https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        if (numbers.size() < 2) return {};
        while (l < r) {
            if (numbers[l] + numbers[r] == target) {
                return {l + 1, r + 1};
            } else if (numbers[l] + numbers[r] > target) {
                r--;
            } else {
                l++;
            }
        }
        return {};
    }
};
