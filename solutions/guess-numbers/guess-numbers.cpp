// @Title: Guess Numbers
// @Author: colinjxc
// @Date: 2019-10-03T12:22:09+08:00
// @URL: https://leetcode-cn.com/problems/guess-numbers


class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        if (guess.size() != answer.size())
            return 0;
        int cnt = 0;
        for (int i = 0; i < guess.size(); i++) {
            if (guess[i] == answer[i]) {
                cnt++;
            }
        }
        return cnt;
    }
};
