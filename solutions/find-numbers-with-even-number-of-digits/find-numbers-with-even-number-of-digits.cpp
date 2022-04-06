// @Title: Find Numbers with Even Number of Digits
// @Author: colinjxc
// @Date: 2021-10-27T19:33:24+08:00
// @URL: https://leetcode-cn.com/problems/find-numbers-with-even-number-of-digits


class Solution {
public:
    int findNumbers(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, [](int a, int b){
            int c = (int)(log10(b) + 1) % 2 == 0;
            return a + c;
        });
    }
};
