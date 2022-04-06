
# [各位相加](https://leetcode-cn.com/problems/add-digits)

## 题目描述

<p>给定一个非负整数 <code>num</code>，反复将各个位上的数字相加，直到结果为一位数。返回这个结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> num =<strong> </strong><code>38</code>
<strong>输出:</strong> 2 
<strong>解释: </strong>各位相加的过程为<strong>：
</strong>38 --&gt; 3 + 8 --&gt; 11
11 --&gt; 1 + 1 --&gt; 2
由于&nbsp;<code>2</code> 是一位数，所以返回 2。
</pre>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> num =<strong> </strong>0
<strong>输出:</strong> 0</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= num &lt;= 2<sup>31</sup>&nbsp;- 1</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你可以不使用循环或者递归，在 <code>O(1)</code> 时间复杂度内解决这个问题吗？</p>


## 题解

### cpp [🔗](add-digits.cpp) 
```cpp
class Solution {
public:
    int addDigits(int num) {
        while (num > 9) {
            int res = 0;
            while (num > 0) {
                res += num%10;
                num /= 10;
            }
            num = res;
        }
        return num;
    }
};
```
### golang [🔗](add-digits.go) 
```golang
func addDigits(num int) int {
    if num > 9 {
        return addDigits(func(n int) int {
            res := 0
            for n > 0 {
                res += n % 10
                n /= 10
            }
            return res
        }(num))
    }
    return num
}
```
### javascript [🔗](add-digits.javascript) 
```javascript
/**
 * @param {number} num
 * @return {number}
 */
var addDigits = function(num) {
    return (num - 1) % 9 + 1
};
```
### python3 [🔗](add-digits.py) 
```python3
class Solution:
    def addDigits(self, num: int) -> int:
        if num < 10:
            return num
        next = 0
        while num > 0:
            next += num%10
            num = num//10
        return self.addDigits(next)
```
### rust [🔗](add-digits.rs) 
```rust
impl Solution {
    pub fn add_digits(num: i32) -> i32 {
        (num - 1) % 9 + 1
    }
}
```


## 相关话题

- [数学](https://leetcode-cn.com/tag/math) 
- [数论](https://leetcode-cn.com/tag/number-theory) 
- [模拟](https://leetcode-cn.com/tag/simulation) 


## 相似题目

- [快乐数](../happy-number/README.md)  [Easy] 


## Links

- [Prev](../binary-tree-paths/README.md) 
- [Next](../ugly-number/README.md) 

