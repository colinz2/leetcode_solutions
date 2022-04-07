
# [螺旋矩阵 II](https://leetcode-cn.com/problems/spiral-matrix-ii)

## 题目描述

<p>给你一个正整数 <code>n</code> ，生成一个包含 <code>1</code> 到 <code>n<sup>2</sup></code> 所有元素，且元素按顺时针顺序螺旋排列的 <code>n x n</code> 正方形矩阵 <code>matrix</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg" style="width: 242px; height: 242px;" />
<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>[[1,2,3],[8,9,4],[7,6,5]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>[[1]]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 20</code></li>
</ul>


## 题解

### cpp [🔗](spiral-matrix-ii.cpp) 
```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        vector<vector<int>> directions = {{0, 1}, {1,0}, {0, -1}, {-1, 0}};
        int curr = 1, total = n*n;

        int i = 0, j = 0;
        int directionIndex = 0;
        while (curr <= total) {
            res[i][j] = curr++;
    
            int x = i + directions[directionIndex][0];
            int y = j + directions[directionIndex][1];
            if ((x == n ^ x < 0) || (y == n ^ y < 0) || res[x][y] != 0) {
                directionIndex = ++directionIndex % 4;
            }
            i += directions[directionIndex][0];
            j += directions[directionIndex][1];
        }

        return res;
    }
};
```


## 相关话题

- [数组](../../tags/array.md) 
- [矩阵](../../tags/matrix.md) 
- [模拟](../../tags/simulation.md) 


## 相似题目

- [螺旋矩阵](../spiral-matrix/README.md)  [Medium] 


## Links

- [Prev](../length-of-last-word/README.md) 
- [Next](../rotate-list/README.md) 

