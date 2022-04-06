// @Title: Fixed Point
// @Author: colinjxc
// @Date: 2022-02-08T04:27:58+08:00
// @URL: https://leetcode-cn.com/problems/fixed-point


class Solution 
{
public:
    int fixedPoint(vector<int>& arr) {
        int lo = 0,  hi = arr.size();
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            if (arr[mid] < mid) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        if (hi == arr.size()) return -1;
        return hi == arr[hi] ? hi : -1;
    }
};
