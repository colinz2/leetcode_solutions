
# [旋转图像](https://leetcode-cn.com/problems/rotate-image)

## 题目描述

<p>给定一个 <em>n&nbsp;</em>×&nbsp;<em>n</em> 的二维矩阵&nbsp;<code>matrix</code> 表示一个图像。请你将图像顺时针旋转 90 度。</p>

<p>你必须在<strong><a href="https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95" target="_blank"> 原地</a></strong> 旋转图像，这意味着你需要直接修改输入的二维矩阵。<strong>请不要 </strong>使用另一个矩阵来旋转图像。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/28/mat1.jpg" style="height: 188px; width: 500px;" />
<pre>
<strong>输入：</strong>matrix = [[1,2,3],[4,5,6],[7,8,9]]
<strong>输出：</strong>[[7,4,1],[8,5,2],[9,6,3]]
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/28/mat2.jpg" style="height: 201px; width: 500px;" />
<pre>
<strong>输入：</strong>matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
<strong>输出：</strong>[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == matrix.length == matrix[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 20</code></li>
	<li><code>-1000 &lt;= matrix[i][j] &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>


## 题解

### cpp [🔗](rotate-image.cpp) 
```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();

        // assert(rowSize, colSize);

        for (int i = 0; i < rowSize / 2; i++) {
            for (int j = 0; j < colSize; j++) {
                std::swap(matrix[i][j], matrix[rowSize - i - 1][j]);
            }
        }

        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < i; j++) {
                if (i != j)
                    std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 
- [数学](https://leetcode-cn.com/tag/math) 
- [矩阵](https://leetcode-cn.com/tag/matrix) 


## 相似题目



## Links

- [Prev](../permutations/README.md) 
- [Next](../group-anagrams/README.md) 

