
# [快乐数](https://leetcode-cn.com/problems/happy-number)

## 题目描述

<p>编写一个算法来判断一个数 <code>n</code> 是不是快乐数。</p>

<p><strong>「快乐数」</strong>&nbsp;定义为：</p>

<ul>
	<li>对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。</li>
	<li>然后重复这个过程直到这个数变为 1，也可能是 <strong>无限循环</strong> 但始终变不到 1。</li>
	<li>如果这个过程 <strong>结果为</strong>&nbsp;1，那么这个数就是快乐数。</li>
</ul>

<p>如果 <code>n</code> 是 <em>快乐数</em> 就返回 <code>true</code> ；不是，则返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 19
<strong>输出：</strong>true
<strong>解释：
</strong>1<sup>2</sup> + 9<sup>2</sup> = 82
8<sup>2</sup> + 2<sup>2</sup> = 68
6<sup>2</sup> + 8<sup>2</sup> = 100
1<sup>2</sup> + 0<sup>2</sup> + 0<sup>2</sup> = 1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


## 题解

### golang [🔗](happy-number.go) 
```golang
func isHappy(n int) bool {
    slow, fast := n, calc(n)
    // 快慢指针， 如果成环快的一定能追的上慢的
    for slow != 1 && slow != fast {
        slow = calc(slow) 
        fast = calc(calc(fast))                                    
    } 
    return fast == 1
}

func calc(n int) int {
    res := 0
    for n > 0 {
        res += (n%10) * (n%10)
        n = n / 10                                    
    }
    return res
}
```
### cpp [🔗](happy-number.cpp) 
```cpp
class Solution {
public:
    bool isHappy(int n) {
        int next = n;
        unordered_set<int> seen;
        
        while (next != 1) {
            next = cal(next);
            if (seen.find(next) != seen.end()) {
                return false;
            }
            seen.insert(next);
        }
        return true;
    }
                                        
private:                                        
    int cal(int n) {
        int res = 0;
        while (n > 0) {
            int nn = n % 10;
            res += nn * nn;                                                                    
            n = n / 10;
        }
        return res;
    }                                   
};
```


## 相关话题

- [哈希表](../../tags/hash-table.md) 
- [数学](../../tags/math.md) 
- [双指针](../../tags/two-pointers.md) 


## 相似题目

- [环形链表](../linked-list-cycle/README.md)  [Easy] 
- [各位相加](../add-digits/README.md)  [Easy] 
- [丑数](../ugly-number/README.md)  [Easy] 


## Links

- [Prev](../number-of-islands/README.md) 
- [Next](../remove-linked-list-elements/README.md) 

