// @Title: Letter Case Permutation
// @Author: colinjxc
// @Date: 2018-12-20T10:55:10+08:00
// @URL: https://leetcode-cn.com/problems/letter-case-permutation


class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        if (S.size() == 0) return {S};
        FindLetterCasePermutation(S, 0, "", res);
        return res;
    }
    void FindLetterCasePermutation(string S, int index, string t, vector<string>& res) {
        if (t.size() == S.size()) {
            res.push_back(t);
            return ;
        }

        if (isalpha(S[index])) {
            char c = isupper(S[index]) ? tolower(S[index]) : toupper(S[index]);
            FindLetterCasePermutation(S, index + 1, t + c, res);

        }
        FindLetterCasePermutation(S, index + 1, t + S[index], res);
    }
};
