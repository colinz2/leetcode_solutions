// @Title: Valid Anagram
// @Author: colinjxc
// @Date: 2022-01-30T01:53:50+08:00
// @URL: https://leetcode-cn.com/problems/valid-anagram


class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[256] = {0,};

        for (auto &c : s) cnt[c]++;
        for (auto &c : t) cnt[c]--;
        return all_of(cnt+'a', cnt+'z' + 1, [](int c){ return  c == 0; });
    }
};
