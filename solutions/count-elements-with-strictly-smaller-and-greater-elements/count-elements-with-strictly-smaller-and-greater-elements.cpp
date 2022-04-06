// @Title: Count Elements With Strictly Smaller and Greater Elements 
// @Author: colinjxc
// @Date: 2022-01-24T20:02:37+08:00
// @URL: https://leetcode-cn.com/problems/count-elements-with-strictly-smaller-and-greater-elements


class Solution {
public:
    int countElements(vector<int>& nums) {
        if (nums.size() < 3) {
            return 0;
        }

        std::sort(nums.begin(), nums.end());
        // the range is  [i, j)
        int i = 0, j = nums.size();

        while (i+2 < j && nums[i] == nums[i+1]) i++;
        while (j > i+2 && nums[j-1] == nums[j-2]) j--;
        
        return j - i - 2;
    }
};
