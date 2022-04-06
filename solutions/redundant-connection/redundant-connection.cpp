// @Title: Redundant Connection
// @Author: colinjxc
// @Date: 2022-01-24T23:14:34+08:00
// @URL: https://leetcode-cn.com/problems/redundant-connection


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> root(2000, -1);
        for (auto &edge : edges) {
            int x = find(root, edge[0]);
            int y = find(root, edge[1]);
            if (x == y) {
                return edge;
            }
            root[x] = y;
        }
        return {};
    }

    int find(vector<int>& root, int p) {
        while (root[p] != -1) {
            p = root[p];
        }
        return p;
    }
};
