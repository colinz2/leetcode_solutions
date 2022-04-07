
# [冗余连接](https://leetcode-cn.com/problems/redundant-connection)

## 题目描述

<p>树可以看成是一个连通且 <strong>无环 </strong>的 <strong>无向 </strong>图。</p>

<p>给定往一棵 <code>n</code> 个节点 (节点值 <code>1～n</code>) 的树中添加一条边后的图。添加的边的两个顶点包含在 <code>1</code> 到 <code>n</code> 中间，且这条附加的边不属于树中已存在的边。图的信息记录于长度为 <code>n</code> 的二维数组 <code>edges</code> ，<code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 表示图中在 <code>ai</code> 和 <code>bi</code> 之间存在一条边。</p>

<p>请找出一条可以删去的边，删除后可使得剩余部分是一个有着 <code>n</code> 个节点的树。如果有多个答案，则返回数组 <code>edges</code> 中最后出现的边。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://pic.leetcode-cn.com/1626676174-hOEVUL-image.png" style="width: 152px; " /></p>

<pre>
<strong>输入:</strong> edges = [[1,2], [1,3], [2,3]]
<strong>输出:</strong> [2,3]
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://pic.leetcode-cn.com/1626676179-kGxcmu-image.png" style="width: 250px; " /></p>

<pre>
<strong>输入:</strong> edges = [[1,2], [2,3], [3,4], [1,4], [1,5]]
<strong>输出:</strong> [1,4]
</pre>

<p> </p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n == edges.length</code></li>
	<li><code>3 <= n <= 1000</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>1 <= ai < bi <= edges.length</code></li>
	<li><code>ai != bi</code></li>
	<li><code>edges</code> 中无重复元素</li>
	<li>给定的图是连通的 </li>
</ul>


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

- [深度优先搜索](../../tags/depth-first-search.md) 
- [广度优先搜索](../../tags/breadth-first-search.md) 
- [并查集](../../tags/union-find.md) 
- [图](../../tags/graph.md) 


## 相似题目



## Links

- [Prev](../second-minimum-node-in-a-binary-tree/README.md) 
- [Next](../top-k-frequent-words/README.md) 

