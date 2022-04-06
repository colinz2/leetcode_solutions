
# [x 的平方根 ](https://leetcode-cn.com/problems/sqrtx)

## 题目描述

<p>给你一个非负整数 <code>x</code> ，计算并返回&nbsp;<code>x</code>&nbsp;的 <strong>算术平方根</strong> 。</p>

<p>由于返回类型是整数，结果只保留 <strong>整数部分 </strong>，小数部分将被 <strong>舍去 。</strong></p>

<p><strong>注意：</strong>不允许使用任何内置指数函数和算符，例如 <code>pow(x, 0.5)</code> 或者 <code>x ** 0.5</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>x = 4
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>x = 8
<strong>输出：</strong>2
<strong>解释：</strong>8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= x &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


## 题解

### cpp [🔗](sqrtx.cpp) 
```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int l = 0, r = x;
        while (l < r) {
            long long mid  = (l + r) / 2;
            if (mid * mid <= (long long)x) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return r-1;
    }
};
```


## 相关话题

- [数学](https://leetcode-cn.com/tag/math) 
- [二分查找](https://leetcode-cn.com/tag/binary-search) 


## 相似题目

- [Pow(x, n)](../powx-n/README.md)  [Medium] 
- [有效的完全平方数](../valid-perfect-square/README.md)  [Easy] 


## Links

- [Prev](../add-binary/README.md) 
- [Next](../climbing-stairs/README.md) 

