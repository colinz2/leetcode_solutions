// @Title: Repeated Substring Pattern
// @Author: colinjxc
// @Date: 2018-12-05T11:28:52+08:00
// @URL: https://leetcode-cn.com/problems/repeated-substring-pattern


class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        string nextStr = str;
        int len = str.length();
        if(len < 1) return false;
        for(int i = 1; i <= len / 2; i++){
            if(len % i == 0){
                nextStr = leftShift(str, i);
                if(nextStr == str) return true;
            }
        }
        return false;
    }
    
    string leftShift(string &str, int l){
        string ret = str.substr(l);
        ret += str.substr(0, l);
        return ret;
    }
};
