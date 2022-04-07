
# [丑数](https://leetcode-cn.com/problems/ugly-number)

## 题目描述

<p><strong>丑数 </strong>就是只包含质因数&nbsp;<code>2</code>、<code>3</code> 和 <code>5</code>&nbsp;的正整数。</p>

<p>给你一个整数 <code>n</code> ，请你判断 <code>n</code> 是否为 <strong>丑数</strong> 。如果是，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 6
<strong>输出：</strong>true
<strong>解释：</strong>6 = 2 × 3</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>true
<strong>解释：</strong>1 没有质因数，因此它的全部质因数是 {2, 3, 5} 的空集。习惯上将其视作第一个丑数。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 14
<strong>输出：</strong>false
<strong>解释：</strong>14 不是丑数，因为它包含了另外一个质因数&nbsp;<code>7 </code>。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


## 题解

### cpp [🔗](ugly-number.cpp) 
```cpp
class Solution {
public:
    bool isUgly(int num) {
        if (num < 1) return false;
            while (num %2 == 0) num >>= 1;
            while (num%3 == 0) num /= 3;
            while (num%5 == 0 ) num /= 5;
        return num == 1;
    }
};
```


## 相关话题

- [数学](../../tags/math.md) 


## 相似题目

- [快乐数](../happy-number/README.md)  [Easy] 
- [计数质数](../count-primes/README.md)  [Medium] 
- [丑数 II](../ugly-number-ii/README.md)  [Medium] 


## Links

- [Prev](../add-digits/README.md) 
- [Next](../ugly-number-ii/README.md) 

