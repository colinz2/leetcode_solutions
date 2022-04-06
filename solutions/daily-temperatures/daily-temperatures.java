// @Title: Daily Temperatures
// @Author: colinjxc
// @Date: 2021-10-27T00:00:57+08:00
// @URL: https://leetcode-cn.com/problems/daily-temperatures


class Solution {
    public int[] dailyTemperatures(int[] T) {
        int[] res = new int[T.length];
        for (int i = 0; i < T.length; i++) {
            for (int j =  i + 1; j < T.length; j++) {
                if (T[j] > T[i]) {
                    res[i] = j - i;
                    break;
                }
            }
        }
        return res;
    }
}
