// @Title: Find the Distance Value Between Two Arrays
// @Author: colinjxc
// @Date: 2022-02-07T22:36:05+08:00
// @URL: https://leetcode-cn.com/problems/find-the-distance-value-between-two-arrays


class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int len1 = arr1.size(), len2 = arr2.size();
        int res = 0;
        for (int i = 0; i < len1; i++) {
            int cnt = 0;
            for (int j = 0; j < len2; j++) {
                if (abs(arr1[i] - arr2[j]) > d) {
                    cnt++;
                }
            }
            res += cnt == len2;
        }
        return res;
    }
};
