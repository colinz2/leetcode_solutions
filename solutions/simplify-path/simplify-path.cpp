// @Title: Simplify Path
// @Author: colinjxc
// @Date: 2018-12-11T00:08:13+08:00
// @URL: https://leetcode-cn.com/problems/simplify-path


class Solution {
public:
    vector<string> split(const string &s, char delim) {
        string item;
        stringstream ss(s);
        vector<string> elems;
        while (getline(ss, item, delim)) {
            if (item == "" || item == ".") {
                continue;
            } else if (item == "..") {
                if (elems.size() > 0)
                    elems.pop_back();
            } else {
                elems.push_back(item);
            }
        }
        return elems;
    }


    string simplifyPath(string path) {
        string result;
        vector<string> elems = split(path, '/');

        for (int i = elems.size() - 1; i >= 0; i--) {
            if (result.size() == 0) {
                result = "/" + elems[i];
            } else {
                result = "/" + elems[i] + result;
            }
        }

        return result.size() ? result : "/";
    }
};
