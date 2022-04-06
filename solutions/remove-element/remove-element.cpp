// @Title: Remove Element
// @Author: colinjxc
// @Date: 2022-01-27T00:26:19+08:00
// @URL: https://leetcode-cn.com/problems/remove-element


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0, k = nums.size();
        while (j < k) {
            if (nums[j] == val) {
                nums[j] = nums[--k];
            } else {
                // 注意这里是 else，避免重复的val之间移动的问题
                j++;
            }
        }

        return k;
    }
};
