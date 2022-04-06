// @Title: Sort Colors
// @Author: colinjxc
// @Date: 2018-11-27T21:03:41+08:00
// @URL: https://leetcode-cn.com/problems/sort-colors


class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cnt(3);
        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
        }

        int k = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                nums[k++] = i;
            }
        }
    }
};
