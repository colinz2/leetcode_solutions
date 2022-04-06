// @Title: Trapping Rain Water
// @Author: colinjxc
// @Date: 2022-01-25T17:40:26+08:00
// @URL: https://leetcode-cn.com/problems/trapping-rain-water


class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int maxLeft = height[0];
        int maxRight = height[height.size()-1];

        int res = 0;
        while (left < right) {
            maxLeft = std::max(maxLeft, height[left]);
            maxRight = std::max(maxRight, height[right]);
            if (height[left] < height[right]) {
                res += maxLeft - height[left];
                left++;
            } else {
                res += maxRight - height[right];
                right--;
            }
        }
        return res;
    }
};
