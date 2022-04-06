// @Title: 最小的k个数  LCOF
// @Author: colinjxc
// @Date: 2022-03-04T01:42:19+08:00
// @URL: https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof


class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        std::vector<int> res;
        if (k == 0) return res;
        std::priority_queue<int, std::vector<int>, std::less<int>> pq;

        for (auto v : arr) {
            if (pq.size() < k) {
                pq.push(v);
            } else {
                if (pq.top() > v) {
                    pq.pop();
                    pq.push(v);
                }
            }
        }
        while (pq.size() > 0) {
            res.emplace_back(pq.top());
            pq.pop();
        }

        return res;      
    }
};
