// @Title: Two Sum Less Than K
// @Author: colinjxc
// @Date: 2022-02-07T23:36:15+08:00
// @URL: https://leetcode-cn.com/problems/two-sum-less-than-k


class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int res = -1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int tmp = nums[i] + nums[j];
                if (tmp < k) {
                    res = max(res, tmp);
                }
            }
        }
        return res;
    }
};
