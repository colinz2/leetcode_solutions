// @Title: Min Stack
// @Author: colinjxc
// @Date: 2022-02-06T22:25:37+08:00
// @URL: https://leetcode-cn.com/problems/min-stack


class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        if (stack_.empty()) {
            stack_.push({val, val});
        } else {
            stack_.push({val, std::min(val, stack_.top().second)});
        }
    }
    
    void pop() {
        stack_.pop();
    }
    
    int top() {
        return stack_.top().first;
    }
    
    int getMin() {
        return stack_.top().second;
    }
private:
    std::stack<std::pair<int,int>> stack_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
