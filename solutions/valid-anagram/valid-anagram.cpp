// @Title: Valid Anagram
// @Author: realzhangm
// @Date: 2021-11-01T22:45:26+08:00
// @URL: https://leetcode-cn.com/problems/valid-anagram


class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[256] = {0,};

        for (auto &c : s) cnt[c - 'a']++;
        for (auto &c : t) cnt[c - 'a']--;
        return all_of(cnt, cnt+32, [](int c){ return  c == 0; });
    }
};
