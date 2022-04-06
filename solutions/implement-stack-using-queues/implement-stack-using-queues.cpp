// @Title: Implement Stack using Queues
// @Author: colinjxc
// @Date: 2021-08-11T11:14:55+08:00
// @URL: https://leetcode-cn.com/problems/implement-stack-using-queues


class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        list_.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = list_.back();
        list_.pop_back();
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return list_.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return list_.empty();
    }
private:
    list<int> list_;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
