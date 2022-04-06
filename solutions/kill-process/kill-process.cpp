// @Title: Kill Process
// @Author: colinjxc
// @Date: 2022-02-06T18:32:33+08:00
// @URL: https://leetcode-cn.com/problems/kill-process


class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> res;
        unordered_map<int, vector<int>> children_map;
        for (int i = 0; i < pid.size(); i++) {
            int _pid = pid[i];
            int _ppid = ppid[i];
            children_map[_ppid].push_back(_pid);
        }

        dfsKill(kill, children_map, res);
        return res;
    }

    void dfsKill(int kill, unordered_map<int, vector<int>>& cmap, vector<int>& res) {
        res.push_back(kill);
        vector<int>& children_pid = cmap[kill];
        for (auto& cpid : children_pid) {
            dfsKill(cpid, cmap, res);
        }
    }
};
