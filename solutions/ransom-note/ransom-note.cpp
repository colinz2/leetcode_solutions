// @Title: Ransom Note
// @Author: colinjxc
// @Date: 2022-01-30T01:15:26+08:00
// @URL: https://leetcode-cn.com/problems/ransom-note


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> cmap;
        for (auto c : magazine) {
            cmap[c]++;
        }
        for (auto c : ransomNote) {
            auto it = cmap.find(c);
            if (it == cmap.end() || it->second == 0) {
                return false;
            }
            it->second--;
        }
        return true;
    }
};
