
# [](https://leetcode-cn.com/problems/factor-combinations)

## 题目描述



## 题解

### cpp [🔗](factor-combinations.cpp) 
```cpp
class Solution {
public:
    vector<vector<int>> getFactors(int n) {

        function<vector<vector<int>>(int, int)> dfs = [&](int n, int start) {
            vector<vector<int>> res;
            for (int i = start; i*i <= n; i++) {
                if (n % i == 0) {
                    res.push_back({i, n / i});
                    for (auto &v : dfs(n / i, i)) {
                        v.push_back(i);
                        res.push_back(v);
                    }
                }
            }
            return res;
        };

        return dfs(n, 2);
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../meeting-rooms/README.md) 
- [Next](../binary-tree-paths/README.md) 

