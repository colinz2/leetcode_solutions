
# [省份数量](https://leetcode-cn.com/problems/number-of-provinces)

## 题目描述

<div class="original__bRMd">
<div>
<p>有 <code>n</code> 个城市，其中一些彼此相连，另一些没有相连。如果城市 <code>a</code> 与城市 <code>b</code> 直接相连，且城市 <code>b</code> 与城市 <code>c</code> 直接相连，那么城市 <code>a</code> 与城市 <code>c</code> 间接相连。</p>

<p><strong>省份</strong> 是一组直接或间接相连的城市，组内不含其他没有相连的城市。</p>

<p>给你一个 <code>n x n</code> 的矩阵 <code>isConnected</code> ，其中 <code>isConnected[i][j] = 1</code> 表示第 <code>i</code> 个城市和第 <code>j</code> 个城市直接相连，而 <code>isConnected[i][j] = 0</code> 表示二者不直接相连。</p>

<p>返回矩阵中 <strong>省份</strong> 的数量。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/24/graph1.jpg" style="width: 222px; height: 142px;" />
<pre>
<strong>输入：</strong>isConnected = [[1,1,0],[1,1,0],[0,0,1]]
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/24/graph2.jpg" style="width: 222px; height: 142px;" />
<pre>
<strong>输入：</strong>isConnected = [[1,0,0],[0,1,0],[0,0,1]]
<strong>输出：</strong>3
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 200</code></li>
	<li><code>n == isConnected.length</code></li>
	<li><code>n == isConnected[i].length</code></li>
	<li><code>isConnected[i][j]</code> 为 <code>1</code> 或 <code>0</code></li>
	<li><code>isConnected[i][i] == 1</code></li>
	<li><code>isConnected[i][j] == isConnected[j][i]</code></li>
</ul>
</div>
</div>


## 题解

### cpp [🔗](number-of-provinces.cpp) 
```cpp
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        std::vector<bool> visited(N, false);

        std::function<void(int)> dfsVisit = [&](int n) {
            if (visited[n]) return;
            visited[n] = true;
            for (int i = 0; i < isConnected[n].size(); i++) {
                if (isConnected[n][i] == 1) {
                    dfsVisit(i);
                }     
            }
        };

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                dfsVisit(i);
                cnt++;
            }
        }
        return cnt;
    }
};
```
### golang [🔗](number-of-provinces.go) 
```golang
func findCircleNum(isConnected [][]int) int {
    pCnt := 0
    vis := make([]bool, len(isConnected))
    
    var dfs func(int)
    dfs = func(from int) {
        vis[from] = true;
        for i, c := range isConnected[from] {
            if c == 1 && !vis[i] {
                dfs(i)
            }
        }
    }

    for i, _:= range isConnected {
        if !vis[i] {
            pCnt++
            dfs(i)
        }
    }
    return pCnt
}
```


## 相关话题

- [深度优先搜索](https://leetcode-cn.com/tag/depth-first-search) 
- [广度优先搜索](https://leetcode-cn.com/tag/breadth-first-search) 
- [并查集](https://leetcode-cn.com/tag/union-find) 
- [图](https://leetcode-cn.com/tag/graph) 


## 相似题目



## Links

- [Prev](../diameter-of-binary-tree/README.md) 
- [Next](../student-attendance-record-i/README.md) 

