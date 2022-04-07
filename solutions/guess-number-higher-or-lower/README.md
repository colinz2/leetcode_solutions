
# [猜数字大小](https://leetcode-cn.com/problems/guess-number-higher-or-lower)

## 题目描述

<p>猜数字游戏的规则如下：</p>

<ul>
	<li>每轮游戏，我都会从 <strong>1</strong> 到 <em><strong>n</strong></em> 随机选择一个数字。 请你猜选出的是哪个数字。</li>
	<li>如果你猜错了，我会告诉你，你猜测的数字比我选出的数字是大了还是小了。</li>
</ul>

<p>你可以通过调用一个预先定义好的接口 <code>int guess(int num)</code> 来获取猜测结果，返回值一共有 3 种可能的情况（<code>-1</code>，<code>1</code> 或 <code>0</code>）：</p>

<ul>
	<li>-1：我选出的数字比你猜的数字小 <code>pick < num</code></li>
	<li>1：我选出的数字比你猜的数字大 <code>pick > num</code></li>
	<li>0：我选出的数字和你猜的数字一样。恭喜！你猜对了！<code>pick == num</code></li>
</ul>

<p>返回我选出的数字。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 10, pick = 6
<strong>输出：</strong>6
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1, pick = 1
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 2, pick = 1
<strong>输出：</strong>1
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>n = 2, pick = 2
<strong>输出：</strong>2
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 2<sup>31</sup> - 1</code></li>
	<li><code>1 <= pick <= n</code></li>
</ul>


## 题解

### cpp [🔗](guess-number-higher-or-lower.cpp) 
```cpp
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int j = 1, k = n;
        while (j <= n) {
            int m = j + (k - j)/2;
            int ret = guess(m);
            if (ret == 0) {
                return m;
            } else if (ret == 1) {
                j = m + 1;
            } else if (ret == -1) {
                k = m - 1;
            } else {
                break;
            }
        } 
        return -1;
    }
};
```
### c [🔗](guess-number-higher-or-lower.c) 
```c
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n){
    int lo = 0, hi = n;
    while (lo <= hi) {
        int m = lo + (hi - lo) / 2;
        int ret = guess(m);
        if (ret == 1) {
            lo = m + 1;
        } else if (ret == -1) {
            hi = m - 1;
        } else {
            return m;
        }
    }
    return -1;
}
```


## 相关话题

- [二分查找](../../tags/binary-search.md) 
- [交互](../../tags/interactive.md) 


## 相似题目

- [第一个错误的版本](../first-bad-version/README.md)  [Easy] 


## Links

- [Prev](../sum-of-two-integers/README.md) 
- [Next](../linked-list-random-node/README.md) 

