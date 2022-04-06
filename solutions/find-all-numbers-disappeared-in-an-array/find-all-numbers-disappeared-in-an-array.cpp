// @Title: Find All Numbers Disappeared in an Array
// @Author: colinjxc
// @Date: 2022-01-29T16:36:04+08:00
// @URL: https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            int index = (nums[i] - 1) % len;
            nums[index] += len;
        }
        for (int i = 0; i < len; i++) {
            if (nums[i] <= len) {
                res.push_back(i+1);
            }
        }
        return res;
    }
};
