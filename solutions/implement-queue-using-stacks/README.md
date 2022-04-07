
# [](https://leetcode-cn.com/problems/implement-queue-using-stacks)

## 题目描述



## 题解

### cpp [🔗](implement-queue-using-stacks.cpp) 
```cpp
class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        rswapStack();
        if (s2.empty()) {
           throw "empty queue";
        }
        int head = s2.top();
        s2.pop();
        return head;
    }
    
    int peek() {
        rswapStack();
        if (s2.empty()) {
           throw "empty queue";
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
private:
    std::stack<int> s1;
    std::stack<int> s2;

    inline void rswapStack() {
        if (!s2.empty()) return;
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```


## 相关话题



## 相似题目



## Links

- [Prev](../power-of-two/README.md) 
- [Next](../palindrome-linked-list/README.md) 

