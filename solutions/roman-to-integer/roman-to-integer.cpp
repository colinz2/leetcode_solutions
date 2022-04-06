// @Title: Roman to Integer
// @Author: colinjxc
// @Date: 2018-11-14T00:09:04+08:00
// @URL: https://leetcode-cn.com/problems/roman-to-integer


class Solution {

public:
    int ToNum(char c, char l) {
        if (c == 'I') return 1;
        else if (c == 'V' && l == 'I') return 3;
        else if (c == 'V') return 5;
        else if (c == 'X' && l == 'I') return 8;
        else if (c == 'X') return 10;
        else if (c == 'L' && l == 'X') return 30;
        else if (c == 'L') return 50;
        else if (c == 'C' && l == 'X') return 80;
        else if (c == 'C') return 100;
        else if (c == 'D' && l == 'C') return 300;
        else if (c == 'D') return 500;
        else if (c == 'M' && l == 'C') return 800;
        else if (c == 'M') return 1000;
        else return 0;
    }

    int romanToInt(string s) {
        int b = 0, n = 0;
        char l = 0;
        for (auto c : s) {
            b = ToNum(c, l);
            n = n + b;
            l = c;
        }
        return n;
    }
};


