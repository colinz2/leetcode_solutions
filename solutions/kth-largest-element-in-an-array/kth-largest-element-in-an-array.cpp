// @Title: Kth Largest Element in an Array
// @Author: realzhangm
// @Date: 2021-11-02T21:31:14+08:00
// @URL: https://leetcode-cn.com/problems/kth-largest-element-in-an-array


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for (auto &v : nums) {
            if (pq.size() == k) {
                if (v > pq.top()) {
                    pq.push(v);
                    pq.pop();
                }
            } else {
                pq.push(v);
            }
        }

        return pq.top();
    }
};
