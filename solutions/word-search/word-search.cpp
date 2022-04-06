// @Title: Word Search
// @Author: colinjxc
// @Date: 2022-02-01T00:45:43+08:00
// @URL: https://leetcode-cn.com/problems/word-search


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 每个点都可以
                if (check(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool check(vector<vector<char>>& board, string& word, int index, int i, int j) {
        if (word.size() == index) {
            return true;
        }
        if (i < 0 || j < 0 || i == board.size() || j == board[0].size()) {
            return false;
        }

        if (word[index] != board[i][j]) {
            return false;
        }
        // 由于不能访问重复路径，过河拆桥
        board[i][j] = 0;
        bool res = check(board, word, index+1, i+1, j) ||
                   check(board, word, index+1, i, j+1) ||
                   check(board, word, index+1, i-1, j) ||
                   check(board, word, index+1, i, j-1);      
        board[i][j] = word[index];
        return res;
    }
};
