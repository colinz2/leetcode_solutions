
# [](https://leetcode-cn.com/problems/transpose-matrix)

## 题目描述



## 题解

### cpp [🔗](transpose-matrix.cpp) 
```cpp
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int row_num = A.size();
        int col_num = A[0].size();
        vector<vector<int>> T(col_num);

        for (int i = 0; i < row_num; i++) {
            for (int j = 0; j < col_num; j++) {
                T[j].push_back(A[i][j]);
            }
        }
        return T;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../lemonade-change/README.md) 
- [Next](../binary-gap/README.md) 

