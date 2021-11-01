// @Title: Binary Prefix Divisible By 5
// @Author: realzhangm
// @Date: 2021-10-29T17:02:33+08:00
// @URL: https://leetcode-cn.com/problems/binary-prefix-divisible-by-5


class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int size = nums.size();
        vector<bool> res(size, false);
        int num = 0;
        for (int i = 0; i < size; i++) {
            num = (num << 1) + nums[i];
            num = num % 5;
            res[i] = (num == 0);
        }
        return res;
    }
};
