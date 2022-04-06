
# [计数质数](https://leetcode-cn.com/problems/count-primes)

## 题目描述

<p>给定整数 <code>n</code> ，返回 <em>所有小于非负整数&nbsp;<code>n</code>&nbsp;的质数的数量</em> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 10
<strong>输出：</strong>4
<strong>解释：</strong>小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 0
<strong>输出：</strong>0
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出</strong>：0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 5 * 10<sup>6</sup></code></li>
</ul>


## 题解

### cpp [🔗](count-primes.cpp) 
```cpp
class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrimeVec(n, 1);
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrimeVec[i]) {
                count++;
                for (int j = 2 * i; j < n; j += i) {
                    isPrimeVec[j] = 0;
                }
            }
        }
        return count;
    }
};
```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 
- [数学](https://leetcode-cn.com/tag/math) 
- [枚举](https://leetcode-cn.com/tag/enumeration) 
- [数论](https://leetcode-cn.com/tag/number-theory) 


## 相似题目

- [丑数](../ugly-number/README.md)  [Easy] 
- [丑数 II](../ugly-number-ii/README.md)  [Medium] 
- [完全平方数](../perfect-squares/README.md)  [Medium] 


## Links

- [Prev](../remove-linked-list-elements/README.md) 
- [Next](../isomorphic-strings/README.md) 

