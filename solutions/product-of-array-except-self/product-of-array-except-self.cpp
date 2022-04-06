// @Title: Product of Array Except Self
// @Author: colinjxc
// @Date: 2022-02-09T22:24:26+08:00
// @URL: https://leetcode-cn.com/problems/product-of-array-except-self


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int kN = nums.size();
        vector<int> res(kN);
        vector<int> p1(kN), p2(kN);

        for (int i = 0, sum1 = 1, sum2 = 1; i < kN; i++) {
            p1[i] = sum1;
            p2[i] = sum2;
            sum1 *= nums[i];
            sum2 *= nums[kN - i - 1];
        }

        for (int i = 0; i < kN; i++) {
            res[i] = (p1[i] * p2[kN - i -1]);
        }
        return res;
    }
};
