// @Title: Number of Provinces
// @Author: realzhangm
// @Date: 2021-10-28T22:19:02+08:00
// @URL: https://leetcode-cn.com/problems/number-of-provinces


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // BFS check 联通分量
        queue<int> q;
        int cnt = 0;
        int n = isConnected.size();
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                q.push(i);
                while (!q.empty()) {
                    int c = q.front(); q.pop();
                    vis[c] = true;
                    for (int j = 0; j < n; j++) {
                        if (isConnected[c][j] == 1 && !vis[j]) {
                            q.push(j);
                        }
                    }
                }
                cnt++;
            }
        } 

        return cnt;
    }
};
