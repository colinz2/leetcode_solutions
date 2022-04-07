
# [杨辉三角](https://leetcode-cn.com/problems/pascals-triangle)

## 题目描述

<p>给定一个非负整数 <em><code>numRows</code>，</em>生成「杨辉三角」的前 <em><code>numRows</code> </em>行。</p>

<p><small>在「杨辉三角」中，每个数是它左上方和右上方的数的和。</small></p>

<p><img alt="" src="https://pic.leetcode-cn.com/1626927345-DZmfxB-PascalTriangleAnimated2.gif" /></p>

<p> </p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> numRows = 5
<strong>输出:</strong> [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> numRows = 1
<strong>输出:</strong> [[1]]
</pre>

<p> </p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 <= numRows <= 30</code></li>
</ul>


## 题解

### cpp [🔗](pascals-triangle.cpp) 
```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> yh_matrics;
        
        for (int i = 0; i < numRows; i++) {
            //初始化，全1.第一行，为1个
            vector<int> row(i + 1, 1);
            yh_matrics.push_back(row);
        }
        if (numRows > 2) {
            for (int i = 2; i < numRows; i++) {
                for (int j = 1; j < i; j++) {
                    //观察规律
                    yh_matrics[i][j] = yh_matrics[i-1][j-1] + yh_matrics[i-1][j];
                }
            }
        }
        
        return yh_matrics;
    }
};
```


## 相关话题

- [数组](../../tags/array.md) 
- [动态规划](../../tags/dynamic-programming.md) 


## 相似题目



## Links

- [Prev](../populating-next-right-pointers-in-each-node-ii/README.md) 
- [Next](../triangle/README.md) 

