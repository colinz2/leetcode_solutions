// @Title: Group Anagrams
// @Author: colinjxc
// @Date: 2022-01-30T10:21:55+08:00
// @URL: https://leetcode-cn.com/problems/group-anagrams


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> smap;
        vector<vector<string>> res;
        for (auto &s : strs) {
            string tmp(s);
            sort(tmp.begin(), tmp.end());
            smap[tmp].push_back(s);
        }
        for (auto &m : smap) {
            res.emplace_back(m.second);
        }

        return res;        
    }
};
