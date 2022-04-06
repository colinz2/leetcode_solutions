// @Title: Evaluate Reverse Polish Notation
// @Author: colinjxc
// @Date: 2022-02-06T00:58:41+08:00
// @URL: https://leetcode-cn.com/problems/evaluate-reverse-polish-notation


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        std::function<void(std::function<int(int,int)>)> eval = [&st]( std::function<int(int,int)> func) {
            int var1 = 0, var2 = 0;
            var1 = st.top(), st.pop();
            var2 = st.top(), st.pop();
            st.push(func(var2, var1));
        };

        for (auto &token : tokens) {
            switch (token[0]) {
                case '+':
                    eval([](int a, int b) {return a + b;});
                    break;
                case '-':
                    if (token.size() > 1) st.push(stoi(token));
                    else eval([](int a, int b) {return a - b;}); 
                    break;
                case '*':
                    eval([](int a, int b) {return a * b;}); 
                    break;
                case '/':
                    eval([](int a, int b) {return a / b;}); 
                    break;
                default:
                    st.push(stoi(token));
            }
        }
        return st.top();
    }
};
