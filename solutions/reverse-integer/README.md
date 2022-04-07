
# [整数反转](https://leetcode-cn.com/problems/reverse-integer)

## 题目描述

<p>给你一个 32 位的有符号整数 <code>x</code> ，返回将 <code>x</code> 中的数字部分反转后的结果。</p>

<p>如果反转后整数超过 32 位的有符号整数的范围 <code>[−2<sup>31</sup>,  2<sup>31 </sup>− 1]</code> ，就返回 0。</p>
<strong>假设环境不允许存储 64 位整数（有符号或无符号）。</strong>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>x = 123
<strong>输出：</strong>321
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>x = -123
<strong>输出：</strong>-321
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>x = 120
<strong>输出：</strong>21
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>x = 0
<strong>输出：</strong>0
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-2<sup>31</sup> <= x <= 2<sup>31</sup> - 1</code></li>
</ul>


## 题解

### cpp [🔗](reverse-integer.cpp) 
```cpp
class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while (x != 0) {
            // 这里不用判断取余了，因为 x 也是 int
            if (ret > INT_MAX/10 || ret  < INT_MIN/10) {
                return 0;
            }
            ret = ret * 10 + x%10;
            x /= 10;
        }
        return ret;
    }
};
```


## 相关话题

- [数学](https://leetcode-cn.com/tag/math) 


## 相似题目

- [字符串转换整数 (atoi)](../string-to-integer-atoi/README.md)  [Medium] 
- [颠倒二进制位](../reverse-bits/README.md)  [Easy] 


## Links

- [Prev](../longest-palindromic-substring/README.md) 
- [Next](../string-to-integer-atoi/README.md) 

