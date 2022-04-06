
# [1 比特与 2 比特字符](https://leetcode-cn.com/problems/1-bit-and-2-bit-characters)

## 题目描述

<p>有两种特殊字符：</p>

<ul>
	<li>第一种字符可以用一比特&nbsp;<code>0</code> 表示</li>
	<li>第二种字符可以用两比特（<code>10</code>&nbsp;或&nbsp;<code>11</code>）表示</li>
</ul>

<p>给你一个以 <code>0</code> 结尾的二进制数组&nbsp;<code>bits</code>&nbsp;，如果最后一个字符必须是一个一比特字符，则返回 <code>true</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre>
<strong>输入:</strong> bits = [1, 0, 0]
<strong>输出:</strong> true
<strong>解释:</strong> 唯一的解码方式是将其解析为一个两比特字符和一个一比特字符。
所以最后一个字符是一比特字符。
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入：</strong>bits = [1,1,1,0]
<strong>输出：</strong>false
<strong>解释：</strong>唯一的解码方式是将其解析为两比特字符和两比特字符。
所以最后一个字符不是一比特字符。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= bits.length &lt;= 1000</code></li>
	<li><code>bits[i]</code> 为 <code>0</code> 或 <code>1</code></li>
</ul>


## 题解

### c [🔗](1-bit-and-2-bit-characters.c) 
```c
bool isOneBitCharacter(int* bits, int bitsSize){
    int i = bitsSize - 2;
    while (i >= 0 && bits[i] == 1)i--;
    return (bitsSize-2-i) % 2 == 0;
}
```
### cpp [🔗](1-bit-and-2-bit-characters.cpp) 
```cpp
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for (int i = 0; i < bits.size();) {
            if (bits[i] == 1 && i + 2 == bits.size()) {
                return false;
            }
            i += bits[i] + 1;
        }
        return true;
    }
};
```
### java [🔗](1-bit-and-2-bit-characters.java) 
```java
class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int i = 0;
        while (i < bits.length - 1) {
            i += bits[i] + 1;
        }
        return i == bits.length - 1;
    }
}
```
### python3 [🔗](1-bit-and-2-bit-characters.py) 
```python3
class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        i = len(bits) - 2
        while i >= 0 and bits[i] == 1:
            i -= 1
        return (len(bits)-2-i) % 2 ==  0
```
### typescript [🔗](1-bit-and-2-bit-characters.typescript) 
```typescript
function isOneBitCharacter(bits: number[]): boolean {
    let i = bits.length - 2
    while (i >= 0 && bits[i] == 1)i--;
    return (bits.length - 2 - i) % 2 == 0

};
```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 


## 相似题目

- [格雷编码](../gray-code/README.md)  [Medium] 


## Links

- [Prev](../max-stack/README.md) 
- [Next](../find-pivot-index/README.md) 

