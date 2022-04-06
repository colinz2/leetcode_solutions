// @Title: Group Shifted Strings
// @Author: colinjxc
// @Date: 2022-01-30T16:17:17+08:00
// @URL: https://leetcode-cn.com/problems/group-shifted-strings


class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> smap;
        for (auto& s : strings) {
            string tmp(s);
            std::transform(tmp.begin(), tmp.end(), tmp.begin(), [&s](char c) {
                return (c - (s[0]-'a') + 26)%26;
            });
            smap[tmp].push_back(s); 
        }

        for (auto &p : smap) {
            res.emplace_back(p.second);
        }
        return res;
    }
};
