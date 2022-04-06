// @Title: Continuous Subarray Sum
// @Author: colinjxc
// @Date: 2022-02-14T21:19:42+08:00
// @URL: https://leetcode-cn.com/problems/continuous-subarray-sum


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m{{0,-1}};
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int t = sum % k;
            auto it = m.find(t);
            if (it != m.end()) {
                if (i - it->second > 1) return true;
            } else{
                m[t] = i;
            }
        }
        return false;
    }
};
