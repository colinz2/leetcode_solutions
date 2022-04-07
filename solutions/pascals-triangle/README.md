
# [](https://leetcode-cn.com/problems/pascals-triangle)

## 题目描述



## 题解

### cpp [🔗](pascals-triangle.cpp) 
```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> yh_matrics;
        
        for (int i = 0; i < numRows; i++) {
            //初始化，全1.第一行，为1个
            vector<int> row(i + 1, 1);
            yh_matrics.push_back(row);
        }
        if (numRows > 2) {
            for (int i = 2; i < numRows; i++) {
                for (int j = 1; j < i; j++) {
                    //观察规律
                    yh_matrics[i][j] = yh_matrics[i-1][j-1] + yh_matrics[i-1][j];
                }
            }
        }
        
        return yh_matrics;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../populating-next-right-pointers-in-each-node-ii/README.md) 
- [Next](../triangle/README.md) 

