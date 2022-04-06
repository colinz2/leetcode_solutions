// @Title: Median of Two Sorted Arrays
// @Author: colinjxc
// @Date: 2022-02-15T22:51:30+08:00
// @URL: https://leetcode-cn.com/problems/median-of-two-sorted-arrays


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (auto n1 : nums1) {
            nums2.push_back(n1);
        }
        sort(nums2.begin(), nums2.end());
        if (nums2.size() % 2) {
            return nums2[nums2.size() / 2];
        }

        return (nums2[nums2.size() / 2] + nums2[nums2.size() / 2 - 1]) / 2.0;
    }
};
