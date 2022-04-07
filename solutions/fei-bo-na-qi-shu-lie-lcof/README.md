
# [斐波那契数列](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof)

## 题目描述

<p>写一个函数，输入 <code>n</code> ，求斐波那契（Fibonacci）数列的第 <code>n</code> 项（即 <code>F(N)</code>）。斐波那契数列的定义如下：</p>

<pre>
F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.</pre>

<p>斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。</p>

<p>答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 5
<strong>输出：</strong>5
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= n <= 100</code></li>
</ul>


## 题解

### cpp [🔗](fei-bo-na-qi-shu-lie-lcof.cpp) 
```cpp
class Solution {
public:
    int fib(int n) {
        int MOD = 1000000007;
        vector<int> fibs(n+2);
        fibs[1] = 1;

        std::function<int(int)> fib_iter = [&](int n) {
            if (fibs[n] > 0 || n == 0) {
                return fibs[n];
            }
            int a = fib_iter(n-2) % MOD;
            int b = fib_iter(n-1) % MOD;
            fibs[n] = (a + b) % MOD;
            return fibs[n];
        };
        return fib_iter(n);
    }
};
```


## 相关话题

- [记忆化搜索](../../tags/memoization.md) 
- [数学](../../tags/math.md) 
- [动态规划](../../tags/dynamic-programming.md) 


## 相似题目



## Links

- [Prev](../yong-liang-ge-zhan-shi-xian-dui-lie-lcof/README.md) 
- [Next](../shu-zu-zhong-zhong-fu-de-shu-zi-lcof/README.md) 

