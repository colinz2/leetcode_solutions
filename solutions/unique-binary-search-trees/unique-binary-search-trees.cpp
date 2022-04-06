// @Title: Unique Binary Search Trees
// @Author: colinjxc
// @Date: 2022-01-31T01:50:42+08:00
// @URL: https://leetcode-cn.com/problems/unique-binary-search-trees


class Solution {
public:
    int numTrees(int n) {
        vector<int> g(n+1);
        g[0] = 1, g[1] = 1;
        // [1 .... n], g(i) 
        // f(i,n) = g(i - 1) * g(n - i), i is root
        // g(n) = \sum\limits_{i=1}^{n} f(i, n) 
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                g[i] += g[j - 1] * g[i - j];
            }
        }

        return g[n];
    }
};
