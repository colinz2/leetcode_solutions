
# [](https://leetcode-cn.com/problems/design-bounded-blocking-queue)

## 题目描述



## 题解

### cpp [🔗](design-bounded-blocking-queue.cpp) 
```cpp
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
```


## 相关话题



## 相似题目



## Links

- [Prev](../print-in-order/README.md) 
- [Next](../print-zero-even-odd/README.md) 

