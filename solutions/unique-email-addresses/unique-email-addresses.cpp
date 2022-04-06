// @Title: Unique Email Addresses
// @Author: colinjxc
// @Date: 2018-12-12T12:37:17+08:00
// @URL: https://leetcode-cn.com/problems/unique-email-addresses


class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> rd;
        for (string email : emails) {
            auto at = email.find("@");
            if (at == string::npos) {
                continue;
            }
            string name = email.substr(0, at);
            auto plus = name.find('+');
            if (plus != string::npos) {
                name = name.substr(0, plus);
            }
            string res = "";
            for (char c: name)
                if (c != '.')
                    res += c;
            res += email.substr(at);
            rd.insert(res);
        }
        return rd.size();
    }
};
