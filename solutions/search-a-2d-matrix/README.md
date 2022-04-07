
# [搜索二维矩阵](https://leetcode-cn.com/problems/search-a-2d-matrix)

## 题目描述

<p>编写一个高效的算法来判断 <code>m x n</code> 矩阵中，是否存在一个目标值。该矩阵具有如下特性：</p>

<ul>
	<li>每行中的整数从左到右按升序排列。</li>
	<li>每行的第一个整数大于前一行的最后一个整数。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/05/mat.jpg" style="width: 322px; height: 242px;" />
<pre>
<strong>输入：</strong>matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/11/25/mat2.jpg" style="width: 322px; height: 242px;" />
<pre>
<strong>输入：</strong>matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
<strong>输出：</strong>false
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 <= m, n <= 100</code></li>
	<li><code>-10<sup>4</sup> <= matrix[i][j], target <= 10<sup>4</sup></code></li>
</ul>


## 题解

### cpp [🔗](search-a-2d-matrix.cpp) 
```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // select raw
        int j = 0, k = matrix.size() - 1;
        while (j <= k) {
            int m = (j+k) >> 1;
            if (matrix[m].front() > target) {
                k = m - 1;
            } else if (matrix[m].back() < target) {
                j = m + 1;
            } else {
                int i = 0, h = matrix[m].size();
                while (i < h) {
                    int mm = (i+h) >> 1;
                    if (matrix[m][mm] < target) {
                        i = mm + 1;
                    } else if (matrix[m][mm] > target) {
                        h = mm;
                    } else {
                        return true;
                    }
                }
                break;
            }
        }
        return false;
    }
};
```


## 相关话题

- [数组](../../tags/array.md) 
- [二分查找](../../tags/binary-search.md) 
- [矩阵](../../tags/matrix.md) 


## 相似题目



## Links

- [Prev](../set-matrix-zeroes/README.md) 
- [Next](../sort-colors/README.md) 

