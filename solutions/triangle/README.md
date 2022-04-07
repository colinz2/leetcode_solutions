
# [三角形最小路径和](https://leetcode-cn.com/problems/triangle)

## 题目描述

<p>给定一个三角形 <code>triangle</code> ，找出自顶向下的最小路径和。</p>

<p>每一步只能移动到下一行中相邻的结点上。<strong>相邻的结点 </strong>在这里指的是 <strong>下标</strong> 与 <strong>上一层结点下标</strong> 相同或者等于 <strong>上一层结点下标 + 1</strong> 的两个结点。也就是说，如果正位于当前行的下标 <code>i</code> ，那么下一步可以移动到下一行的下标 <code>i</code> 或 <code>i + 1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
<strong>输出：</strong>11
<strong>解释：</strong>如下面简图所示：
   <strong>2</strong>
  <strong>3</strong> 4
 6 <strong>5</strong> 7
4 <strong>1</strong> 8 3
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>triangle = [[-10]]
<strong>输出：</strong>-10
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= triangle.length <= 200</code></li>
	<li><code>triangle[0].length == 1</code></li>
	<li><code>triangle[i].length == triangle[i - 1].length + 1</code></li>
	<li><code>-10<sup>4</sup> <= triangle[i][j] <= 10<sup>4</sup></code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong></p>

<ul>
	<li>你可以只使用 <code>O(n)</code> 的额外空间（<code>n</code> 为三角形的总行数）来解决这个问题吗？</li>
</ul>


## 题解

### cpp [🔗](triangle.cpp) 
```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         for(int i = 1 ; i < n ; i ++){

//             triangle[i][0] += triangle[i-1][0];
//             triangle[i][i] += triangle[i-1][i-1];
//             for(int j = 1 ; j < i ; j ++)
//                 triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
//         }
//         return *min_element(triangle[n-1].begin(), triangle[n-1].end());
        
        vector<int> res(triangle.size(), triangle[0][0]);
        for (unsigned int i = 1; i < triangle.size(); i++) 
            for (int j = i; j >= 0; j--) {
                if (j == 0)
                    res[0] += triangle[i][j];
                else if (j == i)
                    res[j] = triangle[i][j] + res[j-1];
                else 
                    res[j] = triangle[i][j] + min(res[j-1], res[j]);
            }
        return *min_element(res.begin(), res.end());
    }
};
```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 
- [动态规划](https://leetcode-cn.com/tag/dynamic-programming) 


## 相似题目



## Links

- [Prev](../pascals-triangle/README.md) 
- [Next](../best-time-to-buy-and-sell-stock/README.md) 

