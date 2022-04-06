// @Title: Detect Capital
// @Author: colinjxc
// @Date: 2018-11-27T18:58:56+08:00
// @URL: https://leetcode-cn.com/problems/detect-capital


class Solution {
public:
    bool detectCapitalUse(string word) {
        bool all_lower = false, all_upper = false, first_upper = false;
        if (isupper(word[0])) {
            all_upper = true;
            first_upper = true;
        } else if (islower(word[0])) {
            all_lower = true;
        }

        for (int i = 1; i < word.size(); i++) {
            int c = word[i];
            if (isupper(c)) {
                all_upper = all_upper & true;
                all_lower = all_lower & false;
                first_upper = first_upper & false;
            } else if (islower(c)) {
                all_upper = all_upper & false;
                all_lower = all_lower & true;
                first_upper = first_upper & true;
            } else {
                all_upper = all_upper & false;
                all_lower = all_lower & false;
                first_upper = first_upper & false;
            }
        }

        return all_lower || all_upper || first_upper;
    }
};
