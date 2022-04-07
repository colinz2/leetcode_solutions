
# [](https://leetcode-cn.com/problems/unique-binary-search-trees)

## 题目描述



## 题解

### cpp [🔗](unique-binary-search-trees.cpp) 
```cpp
class Solution {
public:
    int numTrees(int n) {
        vector<int> g(n+1);
        g[0] = 1, g[1] = 1;
        // [1 .... n], g(i) 
        // f(i,n) = g(i - 1) * g(n - i), i is root
        // g(n) = \sum\limits_{i=1}^{n} f(i, n) 
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                g[i] += g[j - 1] * g[i - j];
            }
        }

        return g[n];
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../binary-tree-inorder-traversal/README.md) 
- [Next](../validate-binary-search-tree/README.md) 

