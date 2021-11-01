
# [各位相加](https://leetcode-cn.com/problems/add-digits)

## 题目描述

<p>给定一个非负整数 <code>num</code>，反复将各个位上的数字相加，直到结果为一位数。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> <code>38</code>
<strong>输出:</strong> 2 
<strong>解释: </strong>各位相加的过程为<strong>：</strong><code>3 + 8 = 11</code>, <code>1 + 1 = 2</code>。 由于&nbsp;<code>2</code> 是一位数，所以返回 2。
</pre>

<p><strong>进阶:</strong><br>
你可以不使用循环或者递归，且在 O(1) 时间复杂度内解决这个问题吗？</p>


## 题解

### cpp [🔗](add-digits.cpp) 
```cpp
class Solution {
public:
    int addDigits(int num) {
        int n = num;
        int next = 0;
        while (n > 9) {
            while (n > 0) {
                next += n % 10;
                n  /= 10;
            }
            n = next;
            next = 0;
        }
        return n;
    }
};
```
### golang [🔗](add-digits.go) 
```golang
func addDigits(num int) int {
    if num < 10 {
        return num
    }
    num = addD(num)
    return addDigits(num)
}

func addD(n int) int {
    sum := 0
    for n > 0 {
        sum += n%10
        n /= 10
    }
    return sum 
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



## Links

- [Prev](../valid-anagram/README.md) 
- [Next](../first-bad-version/README.md) 

