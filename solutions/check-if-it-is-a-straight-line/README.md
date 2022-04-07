
# [](https://leetcode-cn.com/problems/check-if-it-is-a-straight-line)

## 题目描述



## 题解

### cpp [🔗](check-if-it-is-a-straight-line.cpp) 
```cpp
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // (y-y1)/(x-x1) = (y-y2)/(x-x2)
        // (y-y1)*(x-x2) = (y-y2)*(x-x1)
        int x = coordinates[0][0];
        int y = coordinates[0][1];
        for (int i = 1; i < coordinates.size(); i++) {
            int f1 = (y - coordinates[i-1][1]) * (x - coordinates[i][0]);
            int f2 = (y - coordinates[i][1]) * (x - coordinates[i-1][0]);
            if (f1 != f2) return false;
        }
        return true;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../the-dining-philosophers/README.md) 
- [Next](../traffic-light-controlled-intersection/README.md) 

