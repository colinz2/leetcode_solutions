// @Title: Sort Characters By Frequency
// @Author: colinjxc
// @Date: 2021-07-17T20:47:01+08:00
// @URL: https://leetcode-cn.com/problems/sort-characters-by-frequency


class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cmap;
        for (auto &c : s) {
            cmap[c]++; 
        }
        priority_queue< pair<int, char> > pq; 
        for (auto &it :cmap) {
            pq.push(make_pair(it.second, it.first));
        }
        string res;
        while (pq.size() > 0) {
            auto top = pq.top();
            res.append(top.first, top.second);
            pq.pop();
        }
        return res;
    }
};
