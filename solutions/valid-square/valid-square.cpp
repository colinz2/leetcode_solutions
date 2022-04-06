// @Title: Valid Square
// @Author: colinjxc
// @Date: 2018-12-10T17:26:14+08:00
// @URL: https://leetcode-cn.com/problems/valid-square


class Solution {
public:
    int Distance(vector<int>& x, vector<int>& y) {
        int d = abs(x[0] - y[0])*abs(x[0] - y[0]) + 
                    abs(x[1] - y[1])*abs(x[1] - y[1]);
        return d;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> d;
        d.push_back(Distance(p1, p2));
        d.push_back(Distance(p1, p3));
        d.push_back(Distance(p1, p4));
        d.push_back(Distance(p2, p3));
        d.push_back(Distance(p2, p4));
        d.push_back(Distance(p3, p4));
        
        sort(d.begin(), d.end());
        for (int i = 1; i < 4; i++) {
             if (d[i - 1] != d[i]) return false;
        }
        
        if (d[3] == d[4]) return false;
        if (d[4] != d[5]) return false;
        
        return true;
    }
};
