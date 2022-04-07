
# [](https://leetcode-cn.com/problems/max-stack)

## 题目描述



## 题解

### cpp [🔗](max-stack.cpp) 
```cpp
class MaxStack {
public:
    MaxStack() {

    }
    
    void push(int x) {
        stack_.push(x);
        if (stack_max_.empty()) {
            stack_max_.push(x);
        } else {
            stack_max_.push(std::max(peekMax(), x));
        }
    }
    
    int pop() {
        int t = top();
        stack_.pop();
        stack_max_.pop();
        return t;
    }
    
    int top() {
        return stack_.top();
    }
    
    int peekMax() {
        return stack_max_.top();
    }
    
    // 这块很容易写错啊。
    int popMax() {
        int max = peekMax();
        std::stack<int> tmp;
        while (max != top()) {
            tmp.push(pop());
        }
        pop();
        while (!tmp.empty()) {
            push(tmp.top());
            tmp.pop();
        }
        return max;
    }
private:
    std::stack<int> stack_;
    std::stack<int> stack_max_;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
```


## 相关话题



## 相似题目



## Links

- [Prev](../minimum-ascii-delete-sum-for-two-strings/README.md) 
- [Next](../1-bit-and-2-bit-characters/README.md) 

