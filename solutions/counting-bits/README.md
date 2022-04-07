
# [比特位计数](https://leetcode-cn.com/problems/counting-bits)

## 题目描述

<p>给你一个整数 <code>n</code> ，对于&nbsp;<code>0 &lt;= i &lt;= n</code> 中的每个 <code>i</code> ，计算其二进制表示中 <strong><code>1</code> 的个数</strong> ，返回一个长度为 <code>n + 1</code> 的数组 <code>ans</code> 作为答案。</p>

<p>&nbsp;</p>

<div class="original__bRMd">
<div>
<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>[0,1,1]
<strong>解释：</strong>
0 --&gt; 0
1 --&gt; 1
2 --&gt; 10
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 5
<strong>输出：</strong>[0,1,1,2,1,2]
<strong>解释：</strong>
0 --&gt; 0
1 --&gt; 1
2 --&gt; 10
3 --&gt; 11
4 --&gt; 100
5 --&gt; 101
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>很容易就能实现时间复杂度为 <code>O(n log n)</code> 的解决方案，你可以在线性时间复杂度 <code>O(n)</code> 内用一趟扫描解决此问题吗？</li>
	<li>你能不使用任何内置函数解决此问题吗？（如，C++ 中的&nbsp;<code>__builtin_popcount</code> ）</li>
</ul>
</div>
</div>


## 题解

### golang [🔗](counting-bits.go) 
```golang
func countBits(n int) []int {
    res := []int{}
    for i := 0; i < n+1 ; i++ {
        res = append(res, bitCount(i))
    }
    return res
}

func bitCount(n int) int {
    cnt := 0
    for n > 0 {
        n &= (n - 1)
        cnt++
    }
    return cnt
}
```
### cpp [🔗](counting-bits.cpp) 
```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1);
        for (int i = 1; i <= n; i++) {
            bits[i] = bits[i & (i - 1)] + 1;
        }
        return bits;
    }
};
```


## 相关话题

- [位运算](../../tags/bit-manipulation.md) 
- [动态规划](../../tags/dynamic-programming.md) 


## 相似题目

- [位1的个数](../number-of-1-bits/README.md)  [Easy] 


## Links

- [Prev](../house-robber-iii/README.md) 
- [Next](../integer-break/README.md) 

