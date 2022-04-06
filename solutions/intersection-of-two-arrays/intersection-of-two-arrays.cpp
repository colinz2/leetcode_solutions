// @Title: Intersection of Two Arrays
// @Author: colinjxc
// @Date: 2018-12-05T14:16:12+08:00
// @URL: https://leetcode-cn.com/problems/intersection-of-two-arrays


class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> n1(nums1.begin(), nums1.end());
        unordered_set<int> n2(nums2.begin(), nums2.end());
        vector<int> ret;

        for (auto c : n2) {
            if (n1.find(c) != n1.end()) {
                ret.push_back(c);
            }
        }
        return ret;
    }
};
