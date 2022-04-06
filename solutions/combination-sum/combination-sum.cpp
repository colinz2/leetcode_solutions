// @Title: Combination Sum
// @Author: colinjxc
// @Date: 2018-12-17T17:49:30+08:00
// @URL: https://leetcode-cn.com/problems/combination-sum


class Solution {
private:
    void combinationSum(vector<int>& candidates, int index, int target, vector<int>& one, vector<vector<int>>& res) {
        for (int i = index; i < candidates.size(); i++) {
            if (target < candidates[i]) {
                break;
            } else if (target == candidates[i]) {
                one.push_back(candidates[i]);
                res.push_back(one);
                one.pop_back();
            } else {
                one.push_back(candidates[i]);
                //target 为i，\U0001f431
                combinationSum(candidates, i, target - candidates[i], one, res);
                one.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> one;
        sort(candidates.begin(), candidates.end());
        combinationSum(candidates, 0, target, one, res);
        return res;
    }
};

