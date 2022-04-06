
# [不同的二叉搜索树](https://leetcode-cn.com/problems/unique-binary-search-trees)

## 题目描述

<p>给你一个整数 <code>n</code> ，求恰由 <code>n</code> 个节点组成且节点值从 <code>1</code> 到 <code>n</code> 互不相同的 <strong>二叉搜索树</strong> 有多少种？返回满足题意的二叉搜索树的种数。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg" style="width: 600px; height: 148px;" />
<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>5
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 19</code></li>
</ul>


## 题解

### cpp [🔗](unique-binary-search-trees.cpp) 
```cpp
class Solution {
public:
    int numTrees(int n) {
        vector<int> g(n+1);
        g[0] = 1, g[1] = 1;
        // [1 .... n], g(i) 
        // f(i,n) = g(i - 1) * g(n - i), i is root
        // g(n) = \sum\limits_{i=1}^{n} f(i, n) 
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                g[i] += g[j - 1] * g[i - j];
            }
        }

        return g[n];
    }
};
```


## 相关话题

- [树](https://leetcode-cn.com/tag/tree) 
- [二叉搜索树](https://leetcode-cn.com/tag/binary-search-tree) 
- [数学](https://leetcode-cn.com/tag/math) 
- [动态规划](https://leetcode-cn.com/tag/dynamic-programming) 
- [二叉树](https://leetcode-cn.com/tag/binary-tree) 


## 相似题目



## Links

- [Prev](../binary-tree-inorder-traversal/README.md) 
- [Next](../validate-binary-search-tree/README.md) 

