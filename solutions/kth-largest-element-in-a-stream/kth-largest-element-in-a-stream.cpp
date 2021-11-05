// @Title: Kth Largest Element in a Stream
// @Author: realzhangm
// @Date: 2021-11-03T00:18:21+08:00
// @URL: https://leetcode-cn.com/problems/kth-largest-element-in-a-stream


class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k_(k) {
        for (auto &v : nums) {
            add(v);
        }
    }
    
    int add(int val) {
        if (pq_.size() < k_) {
            pq_.push(val);
        } else if (pq_.top() < val) {
            pq_.push(val);
            pq_.pop();
        }
        
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
