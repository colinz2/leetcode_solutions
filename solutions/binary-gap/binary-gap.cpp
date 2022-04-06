// @Title: Binary Gap
// @Author: colinjxc
// @Date: 2018-11-27T16:28:48+08:00
// @URL: https://leetcode-cn.com/problems/binary-gap


class Solution {
public:
    int binaryGap(int N) {
        vector<int> indexes;
        int index = 0;
        while (N){
            if (N & 1)
                indexes.push_back(index);
            index ++;
            N >>= 1;
        }

        int res = 0;
        for (int i = 1 ; i < indexes.size() ; i ++)
            res = max(res, indexes[i] - indexes[i - 1]);

        return res;
    }
};
