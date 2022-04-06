// @Title: Majority Element
// @Author: colinjxc
// @Date: 2022-02-07T11:35:03+08:00
// @URL: https://leetcode-cn.com/problems/majority-element


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = -1, cnt = 0;
        for (auto n : nums) {
            if (cnt == 0) {
                res = n;
            }
            if (res == n) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return res;
    }
};
