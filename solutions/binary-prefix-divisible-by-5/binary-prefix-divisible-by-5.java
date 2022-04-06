// @Title: Binary Prefix Divisible By 5
// @Author: colinjxc
// @Date: 2021-10-27T23:42:39+08:00
// @URL: https://leetcode-cn.com/problems/binary-prefix-divisible-by-5


class Solution {
    // 有限状态机 DFA ？
    public List<Boolean> prefixesDivBy5(int[] nums) {
        List<Boolean> res = new ArrayList<>();
        if (nums.length < 1) {
            return res;
        }
        int StateSet[][] = new int[][]{
                {0, 1},
                {2, 3},
                {4, 0},
                {1, 2},
                {3, 4}
        };
        int state = 0;
        for (int i = 0; i < nums.length; i++) {
            state = StateSet[state][nums[i]];  //转换后的状态
            if (state == 0) {
                res.add(Boolean.TRUE);
            } else {
                res.add(Boolean.FALSE);
            }
        }
        return res;
    }
}
