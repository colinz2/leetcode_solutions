// @Title: Kth Largest Element in a Stream
// @Author: colinjxc
// @Date: 2022-02-10T10:30:45+08:00
// @URL: https://leetcode-cn.com/problems/kth-largest-element-in-a-stream


class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k_(k) {
        for (auto num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        pq_.push(val);
        if (pq_.size() > k_) {
            pq_.pop();
        }
        // if (pq_.size() < k_) {
        //     pq_.push(val);
        // } else {
        //     if (val > pq_.top()) {
        //         pq_.pop();
        //         pq_.push(val);
        //     }
        // }
        return pq_.top();
    }
private:
    int k_;
    priority_queue<int, vector<int>, greater<int>> pq_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
