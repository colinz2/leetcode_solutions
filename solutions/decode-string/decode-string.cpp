// @Title: Decode String
// @Author: colinjxc
// @Date: 2018-12-17T15:12:08+08:00
// @URL: https://leetcode-cn.com/problems/decode-string



class Solution {
public:
    string decodeString(string s) {
        int end;
        return dfs(s, 0, end);
    }

private:
    //s = "3[a]2[bc]", 返回 "aaabcbc".
    //s = "3[a2[c]]", 返回 "accaccacc".
    //s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".
    //\U0001f44c？,
    //\U0001f431啊
    string dfs(string s, int start, int& end) {
        string res = "";
        for (int i = start, b = 0; i < s.size();) {
            if (isdigit(s[i])) {
                int e, n;
                for (b = i; isdigit(s[i]); i++);
                n = stoi(s.substr(b, i - b));
                string sub = dfs(s, i, e);
                //cout << "sub = " << sub << endl;
                while (n--) res += sub;
                i = e;
            } else if (isalpha(s[i])) {
                res += s[i++];
            } else if (s[i] == ']') {
                i++;
                end = i;
                return res;
            } else {
                i++;
            }
        }
        return res;
    }
   
};
