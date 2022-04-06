// @Title: Container With Most Water
// @Author: colinjxc
// @Date: 2022-01-28T00:08:50+08:00
// @URL: https://leetcode-cn.com/problems/container-with-most-water


class Solution {
public:
    int maxArea(vector<int>& height) {
        int j = 0, k = height.size() - 1;
        int max_area = 0;
        while (j < k) {
            int min_height = std::min(height[k], height[j]);
            int area = (k - j) * min_height;
            max_area = std::max(max_area, area);
            if (min_height == height[k]) {
                k--;
            } else {
                j++;
            }
        }
        return max_area;
    }
};
