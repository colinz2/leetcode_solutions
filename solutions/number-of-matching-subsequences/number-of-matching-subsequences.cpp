// @Title: Number of Matching Subsequences
// @Author: colinjxc
// @Date: 2022-02-09T20:20:19+08:00
// @URL: https://leetcode-cn.com/problems/number-of-matching-subsequences


class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        if (words.size() == 0 || s.size() == 0) return 0;
        vector<vector<pair<int, int>>> w(128);
        for (int i = 0; i < words.size(); i++) {
            auto &word = words[i];
            w[word.front()].push_back({i, 0});
        }

        int cnt = 0;
        vector<pair<int, int>> tmp;
        for (auto c : s) {
            tmp.clear();
            tmp.swap(w[c]);

            for (auto &p : tmp) {
                size_t indexInWords = p.first;
                size_t indexOfWord = p.second + 1;
                if (indexOfWord != words[indexInWords].size()) {
                    w[words[indexInWords][indexOfWord]].push_back({indexInWords, indexOfWord});
                } else {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
