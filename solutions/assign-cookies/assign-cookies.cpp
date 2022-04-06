// @Title: Assign Cookies
// @Author: colinjxc
// @Date: 2022-01-28T00:23:24+08:00
// @URL: https://leetcode-cn.com/problems/assign-cookies


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int i = 0, j = 0;
        int ret = 0;
        while (i < g.size() && j < s.size()) {
            if (s[j] < g[i]) {
                j++;
            } else {
                j++;
                i++;
                ret++;
            }
        }
        return ret;
    }
};
