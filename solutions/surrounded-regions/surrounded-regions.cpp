// @Title: Surrounded Regions
// @Author: colinjxc
// @Date: 2022-02-12T19:40:23+08:00
// @URL: https://leetcode-cn.com/problems/surrounded-regions


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board.front().size();
        vector<vector<bool>> visO(m, vector(n, false));
        queue<pair<int,int>> q;

        function<void(int, int)> pushQ = [&](int i, int j) {
            if (i >= 0 && i < m && j >=0 && j < n && board[i][j] == 'O') {
                q.push({i, j});
            }
        };

        for (int i = 0; i < m; i++) {
            pushQ(i, 0), pushQ(i, n-1);
        }
        for (int i = 0; i < n; i++) {
            pushQ(0, i), pushQ(m-1, i);
        }
        
        while (!q.empty()) {
            int i = q.front().first, j = q.front().second; q.pop();
            if (!visO[i][j]) {
                visO[i][j] = true;
                pushQ(i, j-1), pushQ(i-1, j), pushQ(i, j+1), pushQ(i+1, j);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !visO[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
