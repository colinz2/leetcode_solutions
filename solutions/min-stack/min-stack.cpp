// @Title: Min Stack
// @Author: realzhangm
// @Date: 2021-11-02T18:54:44+08:00
// @URL: https://leetcode-cn.com/problems/min-stack


class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        if (stack_.empty()) {
            stack_.push({val, val});
            return;
        }
        int min = getMin();
        min = std::min(min, val);
        stack_.push({val, min});
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
    stack<pair<int, int>> stack_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
