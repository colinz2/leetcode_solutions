// @Title: 用两个栈实现队列 LCOF
// @Author: colinjxc
// @Date: 2022-04-01T21:19:57+08:00
// @URL: https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof


class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        st1.push(value);
    }
    
    int deleteHead() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        if (st2.empty()) {
            return -1;
        }

        int top = st2.top();
        st2.pop();
        return top;
    }
private:
    stack<int> st1;
    stack<int> st2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
