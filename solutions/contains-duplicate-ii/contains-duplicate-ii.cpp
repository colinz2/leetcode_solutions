// @Title: Contains Duplicate II
// @Author: colinjxc
// @Date: 2018-12-05T15:36:44+08:00
// @URL: https://leetcode-cn.com/problems/contains-duplicate-ii


class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            int c = nums[i];
            if (m.count(c) > 0) {
                if (i - m[c] <= k ) return true;
            }
            m[c] = i;
        }
        return false;
    }
};

