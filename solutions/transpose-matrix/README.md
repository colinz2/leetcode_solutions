
# [转置矩阵](https://leetcode-cn.com/problems/transpose-matrix)

## 题目描述

<p>给你一个二维整数数组 <code>matrix</code>， 返回 <code>matrix</code> 的 <strong>转置矩阵</strong> 。</p>

<p>矩阵的 <strong>转置</strong> 是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。</p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/02/10/hint_transpose.png" style="width: 600px; height: 197px;" /></p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>matrix = [[1,2,3],[4,5,6],[7,8,9]]
<strong>输出：</strong>[[1,4,7],[2,5,8],[3,6,9]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>matrix = [[1,2,3],[4,5,6]]
<strong>输出：</strong>[[1,4],[2,5],[3,6]]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 <= m, n <= 1000</code></li>
	<li><code>1 <= m * n <= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> <= matrix[i][j] <= 10<sup>9</sup></code></li>
</ul>


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

- [数组](../../tags/array.md) 
- [矩阵](../../tags/matrix.md) 
- [模拟](../../tags/simulation.md) 


## 相似题目



## Links

- [Prev](../lemonade-change/README.md) 
- [Next](../binary-gap/README.md) 

