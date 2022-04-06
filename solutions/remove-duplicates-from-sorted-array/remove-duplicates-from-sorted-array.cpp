// @Title: Remove Duplicates from Sorted Array
// @Author: colinjxc
// @Date: 2018-11-27T19:30:29+08:00
// @URL: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        if (nums.size() == 0) {
            return 0;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums[j - 1]) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};

