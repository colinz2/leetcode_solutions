// @Title: Generate Parentheses
// @Author: colinjxc
// @Date: 2018-12-17T09:01:37+08:00
// @URL: https://leetcode-cn.com/problems/generate-parentheses


class Solution {
private:
    unordered_set<string> gen_set;
public:
    void generateParenthesisDFS(int left, int right, string s, vector<string>& res) {
        if (left > right) return;
        if (left == 0 && right == 0) {
            res.push_back(s);
        } else {
            if (left)
                generateParenthesisDFS(left - 1, right, s + "(", res);
            if (right)
                generateParenthesisDFS(left, right - 1, s + ")", res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n < 1) return res;
        generateParenthesisDFS(n, n, "", res);
        return res;
    }
};
