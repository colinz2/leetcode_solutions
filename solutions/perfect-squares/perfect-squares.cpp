// @Title: Perfect Squares
// @Author: colinjxc
// @Date: 2018-12-17T16:51:50+08:00
// @URL: https://leetcode-cn.com/problems/perfect-squares


class Solution {

public:
    int numSquares(int n) {

        vector<int> mem(n + 1, -1);

        return numSquares(n, mem);
    }

private:
    int numSquares(int n, vector<int>& mem){

        if(n == 0)
            return 0;

        if(mem[n] != -1)
            return mem[n];

        int res = INT_MAX;
        for(int i = 1; n - i * i >= 0; i ++ )
            res = min(res, 1 + numSquares(n - i * i, mem));
        return mem[n] = res;
    }
};
