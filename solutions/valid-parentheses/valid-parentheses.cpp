// @Title: Valid Parentheses
// @Author: colinjxc
// @Date: 2018-12-11T14:44:11+08:00
// @URL: https://leetcode-cn.com/problems/valid-parentheses


class Solution {
public:
    bool isValid(string s) {
        unordered_map<int, int> symbol_map = {
                {'(', 1},
                {')', -1},
                {'[', 2},
                {']', -2},
                {'{', 3},
                {'}', -3},
        };
        stack<int> s_stack;
        for (auto c : s) {
            int v = symbol_map[c];
            if (v > 0) {
                s_stack.push(v);
            } else if (v < 0) {
                if (s_stack.empty() || s_stack.top() != -v) {
                    return false;
                }
                s_stack.pop();
            }
        }
        if (!s_stack.empty()) return false;
        return true;
    }
};
