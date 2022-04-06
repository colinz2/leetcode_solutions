// @Title: Sliding Window Maximum
// @Author: colinjxc
// @Date: 2022-01-22T20:47:52+08:00
// @URL: https://leetcode-cn.com/problems/sliding-window-maximum


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<std::pair<int, int>> pq;
        for (int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }
        vector<int> res = {pq.top().first};

        // [l, r] window
        int l = 1, r = k;
        while (r < nums.size()) {
            while (!pq.empty() && pq.top().second < l) {
                pq.pop();
            }
            pq.push({nums[r], r});
            res.push_back(pq.top().first);
            l++;
            r++;
        }
        return res;
    }
};
