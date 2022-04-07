
# [](https://leetcode-cn.com/problems/kth-largest-element-in-a-stream)

## 题目描述



## 题解

### cpp [🔗](kth-largest-element-in-a-stream.cpp) 
```cpp
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
```


## 相关话题



## 相似题目



## Links

- [Prev](../search-in-a-sorted-array-of-unknown-size/README.md) 
- [Next](../binary-search/README.md) 

