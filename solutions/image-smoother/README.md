
# [图片平滑器](https://leetcode-cn.com/problems/image-smoother)

## 题目描述

<p><strong>图像平滑器</strong> 是大小为&nbsp;<code>3 x 3</code> 的过滤器，用于对图像的每个单元格平滑处理，平滑处理后单元格的值为该单元格的平均灰度。</p>

<p>每个单元格的<strong>&nbsp; 平均灰度</strong> 定义为：该单元格自身及其周围的 8 个单元格的平均值，结果需向下取整。（即，需要计算蓝色平滑器中 9 个单元格的平均值）。</p>

<p>如果一个单元格周围存在单元格缺失的情况，则计算平均灰度时不考虑缺失的单元格（即，需要计算红色平滑器中 4 个单元格的平均值）。</p>

<p><img src="https://assets.leetcode.com/uploads/2021/05/03/smoother-grid.jpg" style="height: 493px; width: 493px;" /></p>

<p>给你一个表示图像灰度的 <code>m x n</code> 整数矩阵 <code>img</code> ，返回对图像的每个单元格平滑处理后的图像&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2021/05/03/smooth-grid.jpg" /></p>

<pre>
<strong>输入:</strong>img = [[1,1,1],[1,0,1],[1,1,1]]
<strong>输出:</strong>[[0, 0, 0],[0, 0, 0], [0, 0, 0]]
<strong>解释:</strong>
对于点 (0,0), (0,2), (2,0), (2,2): 平均(3/4) = 平均(0.75) = 0
对于点 (0,1), (1,0), (1,2), (2,1): 平均(5/6) = 平均(0.83333333) = 0
对于点 (1,1): 平均(8/9) = 平均(0.88888889) = 0
</pre>

<p><strong>示例 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/03/smooth2-grid.jpg" />
<pre>
<strong>输入:</strong> img = [[100,200,100],[200,50,200],[100,200,100]]
<strong>输出:</strong> [[137,141,137],[141,138,141],[137,141,137]]
<strong>解释:</strong>
对于点 (0,0), (0,2), (2,0), (2,2): floor((100+200+200+50)/4) = floor(137.5) = 137
对于点 (0,1), (1,0), (1,2), (2,1): floor((200+200+50+200+100+100)/6) = floor(141.666667) = 141
对于点 (1,1): floor((50+200+200+200+200+100+100+100+100)/9) = floor(138.888889) = 138
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>m == img.length</code></li>
	<li><code>n == img[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>0 &lt;= img[i][j] &lt;= 255</code></li>
</ul>


## 题解

### cpp [🔗](image-smoother.cpp) 
```cpp
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        if(M.empty()) return vector<vector<int>>();
        vector<vector<int>> result(M.size(), vector<int>(M[0].size(),0));
        vector<pair<int,int>> dir({{-1,-1}, {0,-1}, {1,-1}, {-1,0}, {0,0}, {1,0}, {-1,1}, {0,1}, {1,1}});
        for(int i=0; i<M.size(); i++) {
            for(int j=0; j<M[0].size(); j++) {
                int nume = 0, deno = 0;
                for(const auto& d:dir) {
                    int ii = i+d.first, jj = j+d.second;
                    if(ii>=0 && ii<M.size() && jj>=0 && jj<M[0].size()) {
                        deno++;
                        nume+=M[ii][jj];
                    }
                }
                result[i][j]=nume/deno;
            }
        }
        return result;
    }
};
```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 
- [矩阵](https://leetcode-cn.com/tag/matrix) 


## 相似题目



## Links

- [Prev](../two-sum-iv-input-is-a-bst/README.md) 
- [Next](../second-minimum-node-in-a-binary-tree/README.md) 

