// @Title: Letter Combinations of a Phone Number
// @Author: colinjxc
// @Date: 2022-02-08T20:04:11+08:00
// @URL: https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number


class Solution {
private:
    string digitStr[10] = {"", "", "abc", "def", "ghi", 
                        "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        dfs(0, digits, "", res);
        return res;
    }

    void dfs(int index, string& digits, const string& tmp, vector<string>& res) {
        if (digits.size() == 0) return;
        if (index == digits.size()) {
            res.emplace_back(tmp);
            return;
        }
        int num = digits[index] - '0';
        for (auto& ch : digitStr[num]) {
            dfs(index + 1, digits, tmp + ch, res);
        }
    }
};
