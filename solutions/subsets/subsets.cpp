// @Title: Subsets
// @Author: colinjxc
// @Date: 2018-12-20T22:46:56+08:00
// @URL: https://leetcode-cn.com/problems/subsets


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> one;
        FindSubsets(nums, 0, one, res);
        return res;
    }

private:
    void FindSubsets(vector<int>& nums, int index, vector<int>& one, vector<vector<int>>& res) {
        res.push_back(one);
        for (int i = index; i < nums.size(); i++) {
            one.push_back(nums[i]);
            FindSubsets(nums, i + 1, one, res);
            one.pop_back();
        }
    }
};
