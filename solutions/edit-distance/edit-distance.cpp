// @Title: Edit Distance
// @Author: colinjxc
// @Date: 2022-03-09T11:30:50+08:00
// @URL: https://leetcode-cn.com/problems/edit-distance


class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.size(), vector<int>(word2.size())); 
        return edit(word1, 0, word2, 0, memo); 
    }

    int edit(string& w1, int i, string& w2, int j, vector<vector<int>>& memo) {
        if (i == w1.size()) 
            return w2.size() - j;
        if (j == w2.size()) 
            return w1.size() - i;
        
        // 如果当前相等，没有错误，就编辑下个字符
        if (w1[i] == w2[j]) {
            return edit(w1, i+1, w2, j+1, memo);
        }

        // 如果有记忆就算了
        if (memo[i][j] > 0) {
            return memo[i][j];
        }

        int ins = edit(w1, i, w2, j+1, memo);   // 插入 w2[j] -> w1[i]
        int del = edit(w1, i+1, w2, j, memo);   // 删除 wi[i]
        int sub = edit(w1, i+1, w2, j+1, memo); // 替换 wi[i] <-> w2[j]
        memo[i][j] = std::min({ins, del, sub}) + 1;  // 错误增加
        return memo[i][j];
    }
};
