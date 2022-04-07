
# [](https://leetcode-cn.com/problems/spiral-matrix-ii)

## 题目描述



## 题解

### cpp [🔗](spiral-matrix-ii.cpp) 
```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        vector<vector<int>> directions = {{0, 1}, {1,0}, {0, -1}, {-1, 0}};
        int curr = 1, total = n*n;

        int i = 0, j = 0;
        int directionIndex = 0;
        while (curr <= total) {
            res[i][j] = curr++;
    
            int x = i + directions[directionIndex][0];
            int y = j + directions[directionIndex][1];
            if ((x == n ^ x < 0) || (y == n ^ y < 0) || res[x][y] != 0) {
                directionIndex = ++directionIndex % 4;
            }
            i += directions[directionIndex][0];
            j += directions[directionIndex][1];
        }

        return res;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../length-of-last-word/README.md) 
- [Next](../rotate-list/README.md) 

