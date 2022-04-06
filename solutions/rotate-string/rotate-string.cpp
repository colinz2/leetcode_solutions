// @Title: Rotate String
// @Author: colinjxc
// @Date: 2018-12-11T20:56:10+08:00
// @URL: https://leetcode-cn.com/problems/rotate-string


class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.size() != B.size()) return false;
        
        return (A + A).find(B) != string::npos;
    }
};
