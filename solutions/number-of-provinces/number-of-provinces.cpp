// @Title: Number of Provinces
// @Author: colinjxc
// @Date: 2022-01-25T18:18:44+08:00
// @URL: https://leetcode-cn.com/problems/number-of-provinces


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        std::vector<bool> visited(N, false);

        std::function<void(int)> dfsVisit = [&](int n) {
            if (visited[n]) return;
            visited[n] = true;
            for (int i = 0; i < isConnected[n].size(); i++) {
                if (isConnected[n][i] == 1) {
                    dfsVisit(i);
                }     
            }
        };

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                dfsVisit(i);
                cnt++;
            }
        }
        return cnt;
    }
};
