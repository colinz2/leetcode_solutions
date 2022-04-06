// @Title: Triangle
// @Author: colinjxc
// @Date: 2018-10-23T22:57:53+08:00
// @URL: https://leetcode-cn.com/problems/triangle


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         for(int i = 1 ; i < n ; i ++){

//             triangle[i][0] += triangle[i-1][0];
//             triangle[i][i] += triangle[i-1][i-1];
//             for(int j = 1 ; j < i ; j ++)
//                 triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
//         }
//         return *min_element(triangle[n-1].begin(), triangle[n-1].end());
        
        vector<int> res(triangle.size(), triangle[0][0]);
        for (unsigned int i = 1; i < triangle.size(); i++) 
            for (int j = i; j >= 0; j--) {
                if (j == 0)
                    res[0] += triangle[i][j];
                else if (j == i)
                    res[j] = triangle[i][j] + res[j-1];
                else 
                    res[j] = triangle[i][j] + min(res[j-1], res[j]);
            }
        return *min_element(res.begin(), res.end());
    }
};
