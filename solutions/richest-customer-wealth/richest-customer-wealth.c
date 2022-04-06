// @Title: Richest Customer Wealth
// @Author: colinjxc
// @Date: 2021-10-27T21:28:20+08:00
// @URL: https://leetcode-cn.com/problems/richest-customer-wealth


int maximumWealth(int** accounts, int accountsSize, int* accountsColSize){
    int maxW = 0;
    for (int i = 0; i < accountsSize; i++) {
        int wealthOneAccount = 0;
        for (int j = 0; j < accountsColSize[i]; j++) {
            wealthOneAccount += accounts[i][j];
        }
        if (maxW < wealthOneAccount) {
            maxW = wealthOneAccount;
        } 
    }
    return maxW;
}
