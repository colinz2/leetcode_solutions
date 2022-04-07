
# [加一](https://leetcode-cn.com/problems/plus-one)

## 题目描述

<p>给定一个由 <strong>整数 </strong>组成的<strong> 非空</strong> 数组所表示的非负整数，在该数的基础上加一。</p>

<p>最高位数字存放在数组的首位， 数组中每个元素只存储<strong>单个</strong>数字。</p>

<p>你可以假设除了整数 0 之外，这个整数不会以零开头。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>digits = [1,2,3]
<strong>输出：</strong>[1,2,4]
<strong>解释：</strong>输入数组表示数字 123。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>digits = [4,3,2,1]
<strong>输出：</strong>[4,3,2,2]
<strong>解释：</strong>输入数组表示数字 4321。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>digits = [0]
<strong>输出：</strong>[1]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= digits.length <= 100</code></li>
	<li><code>0 <= digits[i] <= 9</code></li>
</ul>


## 题解

### cpp [🔗](plus-one.cpp) 
```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = false;
        for (auto i = digits.size(); i > 0; i--) {
            digits[i - 1] += 1;
            if (digits[i - 1] == 10) {
                digits[i - 1] = 0;
                carry = true;
            } else {
                carry = false;
                break;
            }
        }
        
        if (carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
```


## 相关话题

- [数组](../../tags/array.md) 
- [数学](../../tags/math.md) 


## 相似题目

- [字符串相乘](../multiply-strings/README.md)  [Medium] 
- [二进制求和](../add-binary/README.md)  [Easy] 
- [给单链表加一](../plus-one-linked-list/README.md)  [Medium] 


## Links

- [Prev](../minimum-path-sum/README.md) 
- [Next](../add-binary/README.md) 

