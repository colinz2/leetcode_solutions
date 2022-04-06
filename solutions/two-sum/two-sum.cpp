// @Title: Two Sum
// @Author: colinjxc
// @Date: 2022-02-09T16:26:31+08:00
// @URL: https://leetcode-cn.com/problems/two-sum


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++) {
            auto it = seen.find(target - nums[i]);
            if (it != seen.end()) {
                return {it->second, i};
            }
            seen[nums[i]] = i;
        }
        return {-1, -1};
    }
};
