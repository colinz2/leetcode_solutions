// @Title: Merge Intervals
// @Author: colinjxc
// @Date: 2022-02-09T21:23:26+08:00
// @URL: https://leetcode-cn.com/problems/merge-intervals


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return {};
        vector<vector<int>> res;
        std::sort(intervals.begin(), intervals.end());

        for (int i = 0, k = 0, end = 0; i < intervals.size(); ) {
            k = i + 1;
            end = intervals[i].back();
            while (k < intervals.size() && intervals[k].front() <= end) {
                end = std::max(end, intervals[k].back());
                k++;
            }
            res.push_back({intervals[i].front(), end});
            i = k;
        }

        return res;
    }
};
