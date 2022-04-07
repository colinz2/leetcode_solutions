
# [](https://leetcode-cn.com/problems/game-of-life)

## 题目描述



## 题解

### cpp [🔗](game-of-life.cpp) 
```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>> &board) {
        int step[][2] = {{1,-1},{1,1},{1,0},{-1,0},{-1,-1},{-1,1},{0,1},{0,-1}};
        int m = board.size();
        int n = m ? board[0].size() : 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live_cnt = 0;
                for (int k = 0; k < sizeof(step)/ sizeof(step[0]); k++) {
                    int new_i = i + step[k][0];
                    int new_j = j + step[k][1];
                    if (new_i >= 0 && new_i < m && new_j >=0 && new_j < n) {
                        int around_p = board[new_i][new_j];
                        if (around_p == 1 || around_p == 2) live_cnt++;
                    }
                }
                if (board[i][j]) {
                    if (live_cnt < 2 || live_cnt > 3) board[i][j] = 2;
                } else {
                    if (live_cnt == 3) board[i][j] = 3;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] > 1)
                    board[i][j] -= 2;
            }
        }
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../move-zeroes/README.md) 
- [Next](../word-pattern/README.md) 

