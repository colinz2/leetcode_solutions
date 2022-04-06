// @Title: Largest Number
// @Author: colinjxc
// @Date: 2022-02-07T16:29:26+08:00
// @URL: https://leetcode-cn.com/problems/largest-number


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](int a, int b) {
            string sa = std::to_string(a), sb = std::to_string(b);
            return sa + sb > sb + sa;
        });

        if (nums[0] == 0) return "0";
        
        std::string res;
        for (auto n : nums) {
            res += std::to_string(n);
        }
        return res;
    }
};
