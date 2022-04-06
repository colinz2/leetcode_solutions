// @Title: Word Search
// @Author: colinjxc
// @Date: 2022-02-01T01:28:19+08:00
// @URL: https://leetcode-cn.com/problems/word-search


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n, word_len = len(board), len(board[0]), len(word)
        def dfs(i, j, k):
            if k == word_len:
                return True
            if not 0 <= i < m or not 0 <= j < n:
                return False
                
            if word[k] != board[i][j]:
                return False
            board[i][j] = '*'

            res = dfs(i-1, j, k+1) or dfs(i+1, j, k+1) or dfs(i, j-1, k+1) or dfs(i, j+1, k+1)
            board[i][j] = word[k]
            return res
            
        for i in range(m):
            for j in range(n):
                if dfs(i, j, 0):
                    return True
        return False
