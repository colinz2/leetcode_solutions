// @Title: Design Bounded Blocking Queue
// @Author: colinjxc
// @Date: 2022-02-10T15:42:26+08:00
// @URL: https://leetcode-cn.com/problems/design-bounded-blocking-queue


class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity) {
        cap_ = capacity;
    }
    
    void enqueue(int element) {
        std::unique_lock<std::mutex> lock(mutex_);
        
        cv_.wait(lock, [this](){ return queue_.size() < cap_; });
        queue_.push(element);
        lock.unlock();

        cv_.notify_all();
    }
    
    int dequeue() {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this](){ return !queue_.empty(); });

        auto head = queue_.front();
        queue_.pop();
        lock.unlock();

        cv_.notify_all();
        return head;
    }
    
    int size() {
        std::unique_lock<std::mutex> lock(mutex_);
        auto size = queue_.size();
        lock.unlock();
        return size;
    }
private:
    int cap_;
    std::queue<int> queue_;
    std::mutex mutex_;
    std::condition_variable cv_;
};
