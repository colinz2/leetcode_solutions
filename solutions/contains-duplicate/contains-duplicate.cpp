// @Title: Contains Duplicate
// @Author: colinjxc
// @Date: 2018-12-05T15:06:57+08:00
// @URL: https://leetcode-cn.com/problems/contains-duplicate


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};
