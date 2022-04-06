// @Title: Maximal Square
// @Author: colinjxc
// @Date: 2022-01-31T22:10:58+08:00
// @URL: https://leetcode-cn.com/problems/maximal-square


int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int min(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}

int min3(int a, int b, int c) {
    return min(min(a, b), c);
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    int* dp[matrixSize];
    for (int i = 0; i < matrixSize; i++) {
        dp[i] = (int*)malloc(sizeof(int)*(matrixColSize[0]));
    }
    int maxWidth = 0;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min3(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1;
                } 
                maxWidth = max(maxWidth, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        free(dp[i]);
    }
    return maxWidth * maxWidth;
}
