// @Title: Longest Common Prefix
// @Author: colinjxc
// @Date: 2018-11-19T10:58:03+08:00
// @URL: https://leetcode-cn.com/problems/longest-common-prefix


class Solution {
public:
    string CommonPrefix(string& a, string& b) {
        //string cp;
        int j = 0;
        for (j = 0; j < a.size() && j < b.size(); j++) {
            if (a[j] == b[j]) {
                //cp.append(1, a[j]);
            } else {
                break;
            }
        }
        //return cp;
        return a.substr(0, j);
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        string lcp = strs[0];
        for (auto i = 0; i < strs.size() - 1; i++) {
            string cp = CommonPrefix(strs[i], strs[i+1]);
            if (cp.size() == 0) {
                return "";
            }
            if (cp.size() < lcp.size()) {
                lcp = cp;
            }
        }
        return  lcp;
    }
};
