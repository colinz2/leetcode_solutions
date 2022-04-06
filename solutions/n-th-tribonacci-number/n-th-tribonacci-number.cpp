// @Title: N-th Tribonacci Number
// @Author: colinjxc
// @Date: 2022-02-09T23:19:58+08:00
// @URL: https://leetcode-cn.com/problems/n-th-tribonacci-number


class Solution {
public:
    int tribonacci(int n) {
        int tri[4] = {0,1,};
        for (int i = 1; i <=n; i++) {
            tri[0] = tri[1];
            tri[1] = tri[2];
            tri[2] = tri[3];
            tri[3] = tri[0] + tri[1] + tri[2];
        }
        return tri[3];
    }
};
