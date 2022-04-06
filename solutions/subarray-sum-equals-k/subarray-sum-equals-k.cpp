// @Title: Subarray Sum Equals K
// @Author: colinjxc
// @Date: 2022-02-14T17:29:53+08:00
// @URL: https://leetcode-cn.com/problems/subarray-sum-equals-k


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map{{0, 1}};
        int res = 0, sum = 0;
        for (auto num : nums) {
            sum += num;
            auto it = map.find(sum - k);
            if (it != map.end()) {
                res += it->second;
            }
            ++map[sum];
        }
        return res;   
    }
};
