
# [判定字符是否唯一](https://leetcode-cn.com/problems/is-unique-lcci)

## 题目描述

<p>实现一个算法，确定一个字符串 <code>s</code> 的所有字符是否全都不同。</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入:</strong> <code>s</code> = &quot;leetcode&quot;
<strong>输出:</strong> false 
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入:</strong> <code>s</code> = &quot;abc&quot;
<strong>输出:</strong> true
</pre>

<p><strong>限制：</strong></p>
<ul>
	<li><code>0 <= len(s) <= 100 </code></li>
	<li>如果你不使用额外的数据结构，会很加分。</li>
</ul>
    

## 题解

### golang [🔗](is-unique-lcci.go) 
```golang
func isUnique(astr string) bool {
    var mask uint32
    for i := range astr {
        bitN := uint32(1 << int(astr[i] - 'a'))
        if bitN & mask > 0 {
            return false
        }
        mask |= bitN
    }
    return true
}
```
### cpp [🔗](is-unique-lcci.cpp) 
```cpp
class Solution {
public:
    bool isUnique(string astr) {
        bool e[256] = {false,};
        for (auto& c : astr) {
            if (e[c]) {
                return false;
            }
            e[c] = true;
        }
        return  true;
    }
};
```


## 相关话题

- [位运算](../../tags/bit-manipulation.md) 
- [哈希表](../../tags/hash-table.md) 
- [字符串](../../tags/string.md) 
- [排序](../../tags/sorting.md) 


## 相似题目



## Links

- [Prev](../guess-numbers/README.md) 
- [Next](../linked-list-cycle-lcci/README.md) 

