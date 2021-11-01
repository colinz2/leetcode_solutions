// @Title: 用两个栈实现队列 LCOF
// @Author: realzhangm
// @Date: 2021-10-29T16:19:10+08:00
// @URL: https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof


class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        if (!s2.empty()) {
            int res = s2.top();
            s2.pop();
            return res;
        }
        return -1;
    }
private:
    stack<int> s1;
    stack<int> s2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
