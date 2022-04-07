
# [](https://leetcode-cn.com/problems/jBjn9C)

## 题目描述



## 题解

### cpp [🔗](jBjn9C.cpp) 
```cpp
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
```


## 相关话题



## 相似题目



## Links

- [Prev](../opLdQZ/README.md) 
- [Next](../N6YdxV/README.md) 

