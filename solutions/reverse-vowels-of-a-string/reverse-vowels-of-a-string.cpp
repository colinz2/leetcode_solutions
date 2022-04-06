// @Title: Reverse Vowels of a String
// @Author: colinjxc
// @Date: 2018-11-28T21:01:35+08:00
// @URL: https://leetcode-cn.com/problems/reverse-vowels-of-a-string


class Solution {
public:
    string reverseVowels(string s) {
        int dict[256] = {0};
        dict['a'] = 1, dict['A'] = 1;
        dict['e'] = 1, dict['E'] = 1;
        dict['i'] = 1, dict['I'] = 1;
        dict['o'] = 1, dict['O'] = 1;
        dict['u'] = 1, dict['U'] = 1;
        int start = 0, end = s.size() - 1;
        while (start < end) {
            while (start < end && !dict[s[start]]) start++;
            while (start < end && !dict[s[end]]) end--;
            swap(s[start], s[end]);
            start++;
            end--;
        }
        return s;
    }
};


