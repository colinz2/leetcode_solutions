
# [3 的幂](https://leetcode-cn.com/problems/power-of-three)

## 题目描述

<p>给定一个整数，写一个函数来判断它是否是 3&nbsp;的幂次方。如果是，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>整数 <code>n</code> 是 3 的幂次方需满足：存在整数 <code>x</code> 使得 <code>n == 3<sup>x</sup></code></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 27
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 0
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 9
<strong>输出：</strong>true
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>n = 45
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能不使用循环或者递归来完成本题吗？</p>


## 题解

### cpp [🔗](power-of-three.cpp) 
```cpp
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0) return false;
        #define log3(n)  log(n)/log(3)
        
        double x = log3(n);
        return abs(x - round(x)) < 1e-10;
    }
};


```
### c [🔗](power-of-three.c) 
```c


bool isPowerOfThree(int n){
    long t = 1;
    while (t < n) {
        t *= 3;
    }
    return n == t;
}
```


## 相关话题

- [递归](../../tags/recursion.md) 
- [数学](../../tags/math.md) 


## 相似题目

- [2 的幂](../power-of-two/README.md)  [Easy] 


## Links

- [Prev](../serialize-and-deserialize-binary-tree/README.md) 
- [Next](../odd-even-linked-list/README.md) 

