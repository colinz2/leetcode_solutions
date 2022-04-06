// @Title: Rotate Array
// @Author: colinjxc
// @Date: 2018-10-16T17:46:03+08:00
// @URL: https://leetcode-cn.com/problems/rotate-array


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto size = nums.size();
        if (size == 1) {
            return ;
        }
        for (auto i = 0; i < k; i++) {
            auto f = nums[0];
            auto e = nums[size - 1];
            for (auto j = size - 1; j > 1; j--) {
                nums[j] = nums[j - 1]; 
            }
            nums[1] = f;
            nums[0] = e;
            //auto new_index = (i + k) % size;
        }
    }
};
