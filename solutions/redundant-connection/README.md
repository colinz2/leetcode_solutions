
# [](https://leetcode-cn.com/problems/redundant-connection)

## 题目描述



## 题解

### cpp [🔗](redundant-connection.cpp) 
```cpp
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> root(2000, -1);
        for (auto &edge : edges) {
            int x = find(root, edge[0]);
            int y = find(root, edge[1]);
            if (x == y) {
                return edge;
            }
            root[x] = y;
        }
        return {};
    }

    int find(vector<int>& root, int p) {
        while (root[p] != -1) {
            p = root[p];
        }
        return p;
    }
};
```
### golang [🔗](redundant-connection.go) 
```golang
func findRedundantConnection(edges [][]int) []int {
    p := make([]int, len(edges) + 1)
    for i := 0; i < len(edges) + 1; i++ {
        p[i] = i
    }

    for _, edge := range edges {
        if find(p, edge[0]) ==  find(p , edge[1]) {
            return edge
        }
        union(p, edge[0], edge[1])
    }
    return []int{}
}

func union(p []int, a, b int) {
    rootA := find(p, a)
    rootB := find(p, b)
    if rootA != rootB {
        p[rootA] = rootB
    }
}

func find(p []int, a int) int {
    if a != p[a] {
        p[a] = find(p, p[a])
    }
    return p[a]
}
```


## 相关话题



## 相似题目



## Links

- [Prev](../second-minimum-node-in-a-binary-tree/README.md) 
- [Next](../top-k-frequent-words/README.md) 

