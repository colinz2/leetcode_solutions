// @Title: Decompress Run-Length Encoded List
// @Author: colinjxc
// @Date: 2022-01-28T20:40:03+08:00
// @URL: https://leetcode-cn.com/problems/decompress-run-length-encoded-list


class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i += 2) {
            int freq = nums[i];
            for (int j = 0; j < freq; j++) {
                res.push_back(nums[i+1]);
            }
        }
        return res;
    }
};
