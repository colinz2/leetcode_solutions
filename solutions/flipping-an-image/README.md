
# [翻转图像](https://leetcode-cn.com/problems/flipping-an-image)

## 题目描述

<p>给定一个<meta charset="UTF-8" />&nbsp;<code>n x n</code>&nbsp;的二进制矩阵&nbsp;<code>image</code>&nbsp;，先 <strong>水平</strong> 翻转图像，然后&nbsp;<strong>反转&nbsp;</strong>图像并返回&nbsp;<em>结果</em>&nbsp;。</p>

<p><strong>水平</strong>翻转图片就是将图片的每一行都进行翻转，即逆序。</p>

<ul>
	<li>例如，水平翻转&nbsp;<code>[1,1,0]</code>&nbsp;的结果是&nbsp;<code>[0,1,1]</code>。</li>
</ul>

<p><strong>反转</strong>图片的意思是图片中的&nbsp;<code>0</code>&nbsp;全部被&nbsp;<code>1</code>&nbsp;替换，&nbsp;<code>1</code>&nbsp;全部被&nbsp;<code>0</code>&nbsp;替换。</p>

<ul>
	<li>例如，反转&nbsp;<code>[0,1,1]</code>&nbsp;的结果是&nbsp;<code>[1,0,0]</code>。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>image = [[1,1,0],[1,0,1],[0,0,0]]
<strong>输出：</strong>[[1,0,0],[0,1,0],[1,1,1]]
<strong>解释：</strong>首先翻转每一行: [[0,1,1],[1,0,1],[0,0,0]]；
     然后反转图片: [[1,0,0],[0,1,0],[1,1,1]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
<strong>输出：</strong>[[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
<strong>解释：</strong>首先翻转每一行: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]]；
     然后反转图片: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<p><meta charset="UTF-8" /></p>

<ul>
	<li><code>n == image.length</code></li>
	<li><code>n == image[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 20</code></li>
	<li><code>images[i][j]</code>&nbsp;==&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code>.</li>
</ul>


## 题解

### cpp [🔗](flipping-an-image.cpp) 
```cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {            
        for (auto &row : A) {
            int row_len = row.size();
            for (int i = 0; i < row_len / 2; i++) {
                int t = 1 - row[i];
                row[i] = 1 - row[row_len -1 - i];
                row[row_len -1 - i] = t;
            }
            if (row_len & 1) {
                row[row_len / 2] = 1 -  row[row_len / 2];
            }
        }
        return A;
    }
    
    
};
```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 
- [双指针](https://leetcode-cn.com/tag/two-pointers) 
- [矩阵](https://leetcode-cn.com/tag/matrix) 
- [模拟](https://leetcode-cn.com/tag/simulation) 


## 相似题目



## Links

- [Prev](../design-circular-queue/README.md) 
- [Next](../peak-index-in-a-mountain-array/README.md) 

