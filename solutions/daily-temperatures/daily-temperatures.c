// @Title: Daily Temperatures
// @Author: colinjxc
// @Date: 2021-10-26T23:58:51+08:00
// @URL: https://leetcode-cn.com/problems/daily-temperatures


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *dailyTemperatures(int *T, int TSize, int *returnSize)
{
    int monoStack[TSize];
    memset(monoStack, 0, sizeof(int) * TSize);
    int stackTop = -1;
    int tIter = 0;

    int *res = (int *)malloc(sizeof(int) * TSize);
    memset(res, 0, sizeof(int) * TSize);

    while (tIter < TSize) {
        /* monoStack[stackTop]是栈顶元素在T中的下标，T[monoStack[stackTop]] 才是真正的栈顶温度 */
        while (stackTop != -1 && T[monoStack[stackTop]] < T[tIter]) {
            int r = monoStack[stackTop];
            stackTop--;
            
            res[r] = tIter - r;
        }
        monoStack[++stackTop] = tIter++;        
    }
    *returnSize = TSize;
    return res;
}

