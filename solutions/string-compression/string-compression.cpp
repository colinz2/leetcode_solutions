// @Title: String Compression
// @Author: colinjxc
// @Date: 2022-02-10T00:04:38+08:00
// @URL: https://leetcode-cn.com/problems/string-compression


class Solution {
public:
    int compress(vector<char>& chars) {
        char prev = 0;
        int cnt = 0;
        int k = 0;
        for (auto c : chars) {
            if (c == prev) {
                cnt++;
            } else {
                if (cnt > 0) {
                    string ss = to_string(cnt + 1);
                    for (auto s : ss) {
                        chars[k++] = s;
                    }
                }
                chars[k++] = c;
                cnt = 0;
            }
            prev = c;
        }
        if (cnt > 0) {
            string ss = to_string(cnt + 1);
            for (auto s : ss) {
                chars[k++] = s;
            }
        }      
        return k;
    }
};
