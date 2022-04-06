// @Title: Hamming Distance
// @Author: colinjxc
// @Date: 2018-10-15T20:09:55+08:00
// @URL: https://leetcode-cn.com/problems/hamming-distance


int hammingDistance(int x, int y) {
    int z = x ^ y;
    int distance = 0;
    while (z > 0) {
        distance += z & 1;
        z = z >> 1;
    }
    return distance;
}
