
# [](https://leetcode-cn.com/problems/flipping-an-image)

## 题目描述



## 题解

### cpp [🔗](flipping-an-image.cpp) 
```cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {            
        for (auto &row : A) {
            int row_len = row.size();
            for (int i = 0; i < row_len / 2; i++) {
                int t = 1 - row[i];
                row[i] = 1 - row[row_len -1 - i];
                row[row_len -1 - i] = t;
            }
            if (row_len & 1) {
                row[row_len / 2] = 1 -  row[row_len / 2];
            }
        }
        return A;
    }
    
    
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../design-circular-queue/README.md) 
- [Next](../peak-index-in-a-mountain-array/README.md) 

