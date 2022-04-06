// @Title: Permutations
// @Author: colinjxc
// @Date: 2022-03-05T13:55:00+08:00
// @URL: https://leetcode-cn.com/problems/permutations


class Solution {
public:
    vector<vector<int>> res;
    vector<bool> vis;
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        vis.resize(nums.size());

        vector<int> tmp;
        backtrack(nums, tmp, 0);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& tmp, int index) {
        if (index == nums.size()) {
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!vis[i]) {
                vis[i] = true;
                tmp.push_back(nums[i]);
                backtrack(nums, tmp, index+1);
                tmp.pop_back();
                vis[i] = false;
            }
        }
    }
};
