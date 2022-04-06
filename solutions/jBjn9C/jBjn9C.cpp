// @Title: 数据流的第 K 大数值
// @Author: colinjxc
// @Date: 2022-03-05T22:43:42+08:00
// @URL: https://leetcode-cn.com/problems/jBjn9C


class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        for (auto n : nums) {
            add(n);
        }
    }
    
    int add(int val) {
        if (pq_.size() < k_) {
            pq_.push(val);
        } else {
            if (pq_.top() < val) {
                pq_.pop();
                pq_.push(val);
            }
        }
        return pq_.top();
    }
private:
    int k_;
    std::priority_queue<int, vector<int>, greater<int>> pq_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
