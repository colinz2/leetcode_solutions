
# [平方数之和](https://leetcode-cn.com/problems/sum-of-square-numbers)

## 题目描述

<p>给定一个非负整数&nbsp;<code>c</code>&nbsp;，你要判断是否存在两个整数 <code>a</code> 和 <code>b</code>，使得&nbsp;<code>a<sup>2</sup> + b<sup>2</sup> = c</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>c = 5
<strong>输出：</strong>true
<strong>解释：</strong>1 * 1 + 2 * 2 = 5
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>c = 3
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= c &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


## 题解

### cpp [🔗](sum-of-square-numbers.cpp) 
```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        int max = (int)sqrt(c) + 1;
        for (int i = 0; i < max; i++) {
            int square = i*i;
            int sub_sqrt = sqrt(c - square);
            if (sub_sqrt*sub_sqrt + square == c) return true;
        }
        return false;
    }
};
```


## 相关话题

- [数学](../../tags/math.md) 
- [双指针](../../tags/two-pointers.md) 
- [二分查找](../../tags/binary-search.md) 


## 相似题目

- [有效的完全平方数](../valid-perfect-square/README.md)  [Easy] 


## Links

- [Prev](../maximum-product-of-three-numbers/README.md) 
- [Next](../average-of-levels-in-binary-tree/README.md) 

