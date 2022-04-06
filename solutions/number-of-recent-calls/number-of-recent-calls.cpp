// @Title: Number of Recent Calls
// @Author: colinjxc
// @Date: 2022-01-31T16:18:31+08:00
// @URL: https://leetcode-cn.com/problems/number-of-recent-calls


class RecentCounter {
public:
    RecentCounter() {

    }
    
    int ping(int t) {
        t_queue_.push(t);
        while (t - t_queue_.front() > 3000) {
            t_queue_.pop();
        }
        return t_queue_.size();
    }
private:
    std::queue<int> t_queue_;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
