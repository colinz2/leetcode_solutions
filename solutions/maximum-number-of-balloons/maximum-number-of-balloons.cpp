// @Title: Maximum Number of Balloons
// @Author: colinjxc
// @Date: 2022-02-13T09:06:15+08:00
// @URL: https://leetcode-cn.com/problems/maximum-number-of-balloons


class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[128] = {0,};
        for (auto c : text) {
            freq[c]++;
        }
        int m1 = std::min(freq['l']/2, freq['o']/2);
        return std::min({freq['b'], freq['a'], freq['n'], m1});
    }
};
