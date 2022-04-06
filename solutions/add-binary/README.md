
# [二进制求和](https://leetcode-cn.com/problems/add-binary)

## 题目描述

<p>给你两个二进制字符串，返回它们的和（用二进制表示）。</p>

<p>输入为 <strong>非空 </strong>字符串且只包含数字&nbsp;<code>1</code>&nbsp;和&nbsp;<code>0</code>。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> a = &quot;11&quot;, b = &quot;1&quot;
<strong>输出:</strong> &quot;100&quot;</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> a = &quot;1010&quot;, b = &quot;1011&quot;
<strong>输出:</strong> &quot;10101&quot;</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>每个字符串仅由字符 <code>&#39;0&#39;</code> 或 <code>&#39;1&#39;</code> 组成。</li>
	<li><code>1 &lt;= a.length, b.length &lt;= 10^4</code></li>
	<li>字符串如果不是 <code>&quot;0&quot;</code> ，就都不含前导零。</li>
</ul>


## 题解

### cpp [🔗](add-binary.cpp) 
```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        string base , adder;
        if (a.size() > b.size()) {
            base = a;
            adder = b;
        } else {
            base = b;
            adder = a;
        }

        int carry = 0;
        for (int i = base.size() - 1, j = adder.size() - 1 ; i >= 0; i--, j--) {
            int sum = 0;
            if (j >= 0) {
               sum = (base[i] - 0x30) + (adder[j] - 0x30) + carry;
            } else {
                sum = base[i] - 0x30 + carry;
            }
            base[i] = (sum % 2) + 0x30;
            carry = sum / 2;
        }

        if (carry) {
            base.insert(base.begin(), '1');
        }

        return base;
    }
};
```


## 相关话题

- [位运算](https://leetcode-cn.com/tag/bit-manipulation) 
- [数学](https://leetcode-cn.com/tag/math) 
- [字符串](https://leetcode-cn.com/tag/string) 
- [模拟](https://leetcode-cn.com/tag/simulation) 


## 相似题目

- [两数相加](../add-two-numbers/README.md)  [Medium] 
- [字符串相乘](../multiply-strings/README.md)  [Medium] 
- [加一](../plus-one/README.md)  [Easy] 


## Links

- [Prev](../plus-one/README.md) 
- [Next](../sqrtx/README.md) 

