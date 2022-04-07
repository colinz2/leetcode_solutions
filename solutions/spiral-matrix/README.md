
# [螺旋矩阵](https://leetcode-cn.com/problems/spiral-matrix)

## 题目描述

<p>给你一个 <code>m</code> 行 <code>n</code> 列的矩阵 <code>matrix</code> ，请按照 <strong>顺时针螺旋顺序</strong> ，返回矩阵中的所有元素。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg" style="width: 242px; height: 242px;" />
<pre>
<strong>输入：</strong>matrix = [[1,2,3],[4,5,6],[7,8,9]]
<strong>输出：</strong>[1,2,3,6,9,8,7,4,5]
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg" style="width: 322px; height: 242px;" />
<pre>
<strong>输入：</strong>matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
<strong>输出：</strong>[1,2,3,4,8,12,11,10,9,5,6,7]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 <= m, n <= 10</code></li>
	<li><code>-100 <= matrix[i][j] <= 100</code></li>
</ul>


## 题解

### cpp [🔗](spiral-matrix.cpp) 
```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int up = 0, down = matrix.size() - 1;
        int left = 0, right = matrix.front().size() - 1;
        vector<int> res;
        for (;;) {
            for (int i = left; i <= right; i++) res.push_back(matrix[up][i]);
            if (++up > down) break;
            
            for (int i = up; i <= down;i++) res.push_back(matrix[i][right]);
            if (--right < left) break;
            
            for (int i = right; i >= left; i--) res.push_back(matrix[down][i]);
            if (--down < up) break;
            
            for (int i = down; i >= up; i--) res.push_back(matrix[i][left]);
            if (++left > right) break;
        }
        return res;
    }
};
```
### python3 [🔗](spiral-matrix.py) 
```python3
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        while matrix:
            res += matrix.pop(0)
            # zip * 解包运算符. like zip(a, b)
            matrix = list(zip(*matrix))[::-1]
        return res
```


## 相关话题

- [数组](../../tags/array.md) 
- [矩阵](../../tags/matrix.md) 
- [模拟](../../tags/simulation.md) 


## 相似题目

- [螺旋矩阵 II](../spiral-matrix-ii/README.md)  [Medium] 


## Links

- [Prev](../maximum-subarray/README.md) 
- [Next](../jump-game/README.md) 

