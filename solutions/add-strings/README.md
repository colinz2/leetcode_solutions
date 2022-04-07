
# [字符串相加](https://leetcode-cn.com/problems/add-strings)

## 题目描述

<p>给定两个字符串形式的非负整数&nbsp;<code>num1</code> 和<code>num2</code>&nbsp;，计算它们的和并同样以字符串形式返回。</p>

<p>你不能使用任何內建的用于处理大整数的库（比如 <code>BigInteger</code>），&nbsp;也不能直接将输入的字符串转换为整数形式。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num1 = "11", num2 = "123"
<strong>输出：</strong>"134"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num1 = "456", num2 = "77"
<strong>输出：</strong>"533"
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>num1 = "0", num2 = "0"
<strong>输出：</strong>"0"
</pre>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num1.length, num2.length &lt;= 10<sup>4</sup></code></li>
	<li><code>num1</code> 和<code>num2</code> 都只包含数字&nbsp;<code>0-9</code></li>
	<li><code>num1</code> 和<code>num2</code> 都不包含任何前导零</li>
</ul>


## 题解

### cpp [🔗](add-strings.cpp) 
```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        string base = num2, adder = num1;
        int carry = 0;
        if (num1.size() > num2.size()) {
            base = num1;
            adder = num2;
        }
        for (int i = base.size() - 1, j = adder.size() - 1 ; i >= 0; i--, j--) {
            int sum = 0;
            if (j >= 0) {
                sum = (base[i] - 0x30) + (adder[j] - 0x30) + carry;
            } else {
                sum = base[i] - 0x30 + carry;
            }
            base[i] = (sum % 10) + 0x30;
            carry = sum / 10;
        }

        if (carry) {
            base.insert(base.begin(), '1');
        }
        return base;
    }
};

```


## 相关话题

- [数学](https://leetcode-cn.com/tag/math) 
- [字符串](https://leetcode-cn.com/tag/string) 
- [模拟](https://leetcode-cn.com/tag/simulation) 


## 相似题目

- [两数相加](../add-two-numbers/README.md)  [Medium] 
- [字符串相乘](../multiply-strings/README.md)  [Medium] 


## Links

- [Prev](../fizz-buzz/README.md) 
- [Next](../number-of-segments-in-a-string/README.md) 

