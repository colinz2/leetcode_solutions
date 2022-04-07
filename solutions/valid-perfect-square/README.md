
# [有效的完全平方数](https://leetcode-cn.com/problems/valid-perfect-square)

## 题目描述

<p>给定一个 <strong>正整数</strong> <code>num</code> ，编写一个函数，如果 <code>num</code> 是一个完全平方数，则返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p><strong>进阶：不要</strong> 使用任何内置的库函数，如  <code>sqrt</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num = 16
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num = 14
<strong>输出：</strong>false
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= num <= 2^31 - 1</code></li>
</ul>


## 题解

### golang [🔗](valid-perfect-square.go) 
```golang
func isPerfectSquare(num int) bool {
    lo, hi := int64(0), int64(num)
    var square int64 = 0 
    for lo <= hi {
        mid := int64(lo + (hi - lo)/2)
        square = mid * mid
        if square > int64(num) {
            hi = mid -1
        } else if square < int64(num) {
            lo = mid + 1
        } else {
            return true
        }
    }
    return false
}
```
### cpp [🔗](valid-perfect-square.cpp) 
```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        long square = 1, n = 1;
        while (square <= num) {
            square = n*n;
            if (square == num) return true;
            n++;
        }
        return false;
    }
};
```


## 相关话题

- [数学](https://leetcode-cn.com/tag/math) 
- [二分查找](https://leetcode-cn.com/tag/binary-search) 


## 相似题目

- [x 的平方根 ](../sqrtx/README.md)  [Easy] 
- [平方数之和](../sum-of-square-numbers/README.md)  [Medium] 


## Links

- [Prev](../design-twitter/README.md) 
- [Next](../plus-one-linked-list/README.md) 

