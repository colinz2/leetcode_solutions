// @Title: Summary Ranges
// @Author: colinjxc
// @Date: 2022-02-08T01:29:45+08:00
// @URL: https://leetcode-cn.com/problems/summary-ranges


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.size() == 0) return res;

        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 == nums.size() || nums[i] + 1 != nums[i+1]) {
                string tmp_str;
                if (i == left) {
                    tmp_str = std::to_string(nums[i]); 
                } else {
                    tmp_str = to_string(nums[left]) + "->" + to_string(nums[i]);
                }
                res.emplace_back(tmp_str);
                left = i + 1;
            }
        }
        return res;
    }
};
