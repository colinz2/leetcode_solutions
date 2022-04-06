// @Title: Longest Consecutive Sequence
// @Author: colinjxc
// @Date: 2022-01-24T21:01:42+08:00
// @URL: https://leetcode-cn.com/problems/longest-consecutive-sequence


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set;
        int max_len = 0;
        for (auto &n : nums) {
            nums_set.insert(n);
        }

        for (auto &n : nums) {
            // 从起点开始
            if (nums_set.count(n-1) == 0) {
                int next = n;
                while(nums_set.count(next)) {
                    next++;
                }
                max_len = std::max(max_len, next - n);
            }
        }

        return max_len;
    }
};
