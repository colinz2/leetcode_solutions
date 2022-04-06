// @Title: Implement Queue using Stacks
// @Author: colinjxc
// @Date: 2022-01-10T20:12:45+08:00
// @URL: https://leetcode-cn.com/problems/implement-queue-using-stacks


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
