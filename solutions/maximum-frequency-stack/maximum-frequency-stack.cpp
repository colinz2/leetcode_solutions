// @Title: Maximum Frequency Stack
// @Author: colinjxc
// @Date: 2022-02-06T11:32:54+08:00
// @URL: https://leetcode-cn.com/problems/maximum-frequency-stack


class FreqStack {
public:
    FreqStack() {
        max_freq_ = 0;
    }
    
    void push(int val) {
        int cntofval = 1 + freqs_[val];
        max_freq_ = std::max(max_freq_, cntofval);
        freqs_[val] = cntofval;
        stacks_[cntofval].push(val);
    }
    
    int pop() {
        if (stacks_[max_freq_].size() == 0) {
            throw "no value";
        }
        int top = stacks_[max_freq_].top();
        stacks_[max_freq_].pop();
        freqs_[top]--;
        if (stacks_[max_freq_].size() == 0) max_freq_--;
        return top;
    }
private:
    std::unordered_map<int, int> freqs_;
    std::unordered_map<int, std::stack<int>> stacks_;
    int max_freq_;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
