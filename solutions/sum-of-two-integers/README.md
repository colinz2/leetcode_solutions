
# [两整数之和](https://leetcode-cn.com/problems/sum-of-two-integers)

## 题目描述

<p>给你两个整数 <code>a</code> 和 <code>b</code> ，<strong>不使用 </strong>运算符&nbsp;<code>+</code> 和&nbsp;<code>-</code>&nbsp;​​​​​​​，计算并返回两整数之和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>a = 1, b = 2
<strong>输出：</strong>3
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>a = 2, b = 3
<strong>输出：</strong>5
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-1000 &lt;= a, b &lt;= 1000</code></li>
</ul>


## 题解

### cpp [🔗](sum-of-two-integers.cpp) 
```cpp
class Solution {
public:
    int getSum(int a, int b) {
        //使用符号了
        //return a + b;
        int sum = a;
        while (b != 0) {
            sum = a ^ b;//calculate sum of a and b without thinking the carry 
            b = (a & b) << 1;//calculate the carry
            a = sum;//add sum(without carry) and carry
        }
        return sum;
    }
};
```


## 相关话题

- [位运算](../../tags/bit-manipulation.md) 
- [数学](../../tags/math.md) 


## 相似题目

- [两数相加](../add-two-numbers/README.md)  [Medium] 


## Links

- [Prev](../plus-one-linked-list/README.md) 
- [Next](../guess-number-higher-or-lower/README.md) 

