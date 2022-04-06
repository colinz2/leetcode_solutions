// @Title: Validate IP Address
// @Author: colinjxc
// @Date: 2022-01-26T18:41:03+08:00
// @URL: https://leetcode-cn.com/problems/validate-ip-address


class Solution {
public:
    void splitString(const string& str, vector<string>& res, char delim=' ') {
        istringstream in(str);
        string line;
        while (std::getline(in, line, delim)) {
            res.emplace_back(line);
        }
        if (!str.empty() && str.back() == delim) {
            res.push_back("");
        }
    }

    bool IsIPv4(const string& ip) {
        vector<string> digits;
        splitString(ip, digits, '.');
        if (digits.size() != 4) return false;
        for (auto& d : digits) {
            if (d.size() > 1 && d[0] == '0') return false;
            for (auto& c: d) {
                if (!std::isdigit(c)) return false;
            }
            int n = stoi(d);
            if (n < 0 || n > 255) return false;
        }
        return true;
    }

    bool IsIPv6(const string& ip) {
        vector<string> digits;
        splitString(ip, digits, ':');
        if (digits.size() != 8) return false;
        for (auto& d : digits) {
            if (d.size() > 4 || d.size() == 0) return false;
            for (auto& c : d) {
                auto lower = tolower(c);
                if (!isdigit(c) && !('a' <= lower && lower <= 'f' )) return false;
            }
        }
        return true;
    }

    string validIPAddress(string queryIP) {
        try {
            if (IsIPv4(queryIP)) {
                return "IPv4";
            } else if (IsIPv6(queryIP)) {
                return "IPv6";
            }
            
        } catch (std::exception& e) {
            return "Neither";
        }
        return "Neither";
    }
};
