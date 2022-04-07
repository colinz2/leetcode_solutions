
# [汉明距离](https://leetcode-cn.com/problems/hamming-distance)

## 题目描述

<p>两个整数之间的 <a href="https://baike.baidu.com/item/%E6%B1%89%E6%98%8E%E8%B7%9D%E7%A6%BB">汉明距离</a> 指的是这两个数字对应二进制位不同的位置的数目。</p>

<p>给你两个整数 <code>x</code> 和 <code>y</code>，计算并返回它们之间的汉明距离。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>x = 1, y = 4
<strong>输出：</strong>2
<strong>解释：</strong>
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
上面的箭头指出了对应二进制位不同的位置。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>x = 3, y = 1
<strong>输出：</strong>1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= x, y <= 2<sup>31</sup> - 1</code></li>
</ul>


## 题解

### python3 [🔗](hamming-distance.py) 
```python3
class Solution:
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        xor = x ^ y
        d = 0
        while xor > 0:
            d += xor & 1
            xor >>= 1
        return d
        
```
### c [🔗](hamming-distance.c) 
```c
int hammingDistance(int x, int y) {
    int z = x ^ y;
    int distance = 0;
    while (z > 0) {
        distance += z & 1;
        z = z >> 1;
    }
    return distance;
}
```
### cpp [🔗](hamming-distance.cpp) 
```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance = 0;
        int z = x ^ y;
        while (z) {
            distance += (z & 0x01);
            z >>= 1;
        }
        return distance;              
    }
};
```
### golang [🔗](hamming-distance.go) 
```golang
func hammingDistance(x int, y int) int {
	res := 0
	z := x ^ y
	for z != 0 {
		if z&1 == 1 {
			res++
		}
		z >>= 1
	}
	return res
}

```


## 相关话题

- [位运算](../../tags/bit-manipulation.md) 


## 相似题目

- [位1的个数](../number-of-1-bits/README.md)  [Easy] 


## Links

- [Prev](../repeated-substring-pattern/README.md) 
- [Next](../validate-ip-address/README.md) 

