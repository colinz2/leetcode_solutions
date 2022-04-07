
# [最大数值](https://leetcode-cn.com/problems/maximum-lcci)

## 题目描述

<p>编写一个方法，找出两个数字<code>a</code>和<code>b</code>中最大的那一个。不得使用if-else或其他比较运算符。</p>
<p><strong>示例：</strong></p>
<pre><strong>输入：</strong> a = 1, b = 2
<strong>输出：</strong> 2
</pre>


## 题解

### cpp [🔗](maximum-lcci.cpp) 
```cpp
class Solution {
public:
    int maximum(int a, int b) {
        long _sum = long(a) + long(b);
        long _diff = long(a) - long(b);
        long _abs_diff = (_diff ^ (_diff >> 63)) - (_diff >> 63);
        return (_sum + _abs_diff) / 2;
    }
};
```


## 相关话题

- [位运算](../../tags/bit-manipulation.md) 
- [脑筋急转弯](../../tags/brainteaser.md) 
- [数学](../../tags/math.md) 


## 相似题目



## Links

- [Prev](../er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/README.md) 
- [Next](../kth-node-from-end-of-list-lcci/README.md) 

