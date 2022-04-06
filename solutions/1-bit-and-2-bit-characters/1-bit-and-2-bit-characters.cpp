// @Title: 1-bit and 2-bit Characters
// @Author: colinjxc
// @Date: 2022-02-02T15:34:15+08:00
// @URL: https://leetcode-cn.com/problems/1-bit-and-2-bit-characters


class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for (int i = 0; i < bits.size();) {
            if (bits[i] == 1 && i + 2 == bits.size()) {
                return false;
            }
            i += bits[i] + 1;
        }
        return true;
    }
};
