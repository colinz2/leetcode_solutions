
# [丑数 II](https://leetcode-cn.com/problems/ugly-number-ii)

## 题目描述

<p>给你一个整数 <code>n</code> ，请你找出并返回第 <code>n</code> 个 <strong>丑数</strong> 。</p>

<p><strong>丑数 </strong>就是只包含质因数 <code>2</code>、<code>3</code> 和/或 <code>5</code> 的正整数。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 10
<strong>输出：</strong>12
<strong>解释：</strong>[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>1
<strong>解释：</strong>1 通常被视为丑数。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 1690</code></li>
</ul>


## 题解

### cpp [🔗](ugly-number-ii.cpp) 
```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1, 1);
        int i2 = 0, i3 = 0, i5 = 0;
        while (res.size() < n) {
            int m2 = res[i2] * 2, m3 = res[i3] * 3, m5 = res[i5] * 5;
            int mn = min(m2, min(m3, m5));
            if (mn == m2) ++i2;
            if (mn == m3) ++i3;
            if (mn == m5) ++i5;
            res.push_back(mn);
        }
        return res.back();
    }
};
```


## 相关话题

- [哈希表](https://leetcode-cn.com/tag/hash-table) 
- [数学](https://leetcode-cn.com/tag/math) 
- [动态规划](https://leetcode-cn.com/tag/dynamic-programming) 
- [堆（优先队列）](https://leetcode-cn.com/tag/heap-priority-queue) 


## 相似题目

- [合并K个升序链表](../merge-k-sorted-lists/README.md)  [Hard] 
- [计数质数](../count-primes/README.md)  [Medium] 
- [丑数](../ugly-number/README.md)  [Easy] 
- [完全平方数](../perfect-squares/README.md)  [Medium] 


## Links

- [Prev](../ugly-number/README.md) 
- [Next](../palindrome-permutation/README.md) 

