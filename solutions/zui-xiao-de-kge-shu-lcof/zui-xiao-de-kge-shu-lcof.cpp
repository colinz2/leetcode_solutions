// @Title: 最小的k个数  LCOF
// @Author: realzhangm
// @Date: 2021-11-02T20:22:49+08:00
// @URL: https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof


class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        priority_queue<int, vector<int>, less<int> > pq;
        if (k == 0) {
            return res;
        }

        for (auto &v : arr) {
            if (pq.size() < k) {
                pq.push(v);
            } else {
                if (pq.top() > v) {
                    pq.pop();
                    pq.push(v);
                }
            }
        }

        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }

        return res; 
    }
};
