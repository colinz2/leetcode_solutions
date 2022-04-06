// @Title: Search Insert Position
// @Author: colinjxc
// @Date: 2022-02-08T03:44:31+08:00
// @URL: https://leetcode-cn.com/problems/search-insert-position


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int j = 0, k = nums.size();
        while (j < k) {
            int m = j + (k -j )/2;
            if (nums[m] < target) {
                j = m + 1;
            } else  {
                k = m; 
            }
        }
        return k;
    }
};
