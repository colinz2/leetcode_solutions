
# [最大频率栈](https://leetcode-cn.com/problems/maximum-frequency-stack)

## 题目描述

<p>设计一个类似堆栈的数据结构，将元素推入堆栈，并从堆栈中弹出<strong>出现频率</strong>最高的元素。</p>

<p>实现 <code>FreqStack</code>&nbsp;类:</p>

<ul>
	<li><meta charset="UTF-8" /><code>FreqStack()</code>&nbsp;构造一个空的堆栈。</li>
	<li><meta charset="UTF-8" /><code>void push(int val)</code>&nbsp;将一个整数&nbsp;<code>val</code>&nbsp;压入栈顶。</li>
	<li><meta charset="UTF-8" /><code>int pop()</code>&nbsp;删除并返回堆栈中出现频率最高的元素。
	<ul>
		<li>如果出现频率最高的元素不只一个，则移除并返回最接近栈顶的元素。</li>
	</ul>
	</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
<strong>输出：</strong>[null,null,null,null,null,null,null,5,7,5,4]
<strong>解释：</strong>
FreqStack = new FreqStack();
freqStack.push (5);//堆栈为 [5]
freqStack.push (7);//堆栈是 [5,7]
freqStack.push (5);//堆栈是 [5,7,5]
freqStack.push (7);//堆栈是 [5,7,5,7]
freqStack.push (4);//堆栈是 [5,7,5,7,4]
freqStack.push (5);//堆栈是 [5,7,5,7,4,5]
freqStack.pop ();//返回 5 ，因为 5 出现频率最高。堆栈变成 [5,7,5,7,4]。
freqStack.pop ();//返回 7 ，因为 5 和 7 出现频率最高，但7最接近顶部。堆栈变成 [5,7,5,4]。
freqStack.pop ();//返回 5 ，因为 5 出现频率最高。堆栈变成 [5,7,4]。
freqStack.pop ();//返回 4 ，因为 4, 5 和 7 出现频率最高，但 4 是最接近顶部的。堆栈变成 [5,7]。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= val &lt;= 10<sup>9</sup></code></li>
	<li><code>push</code>&nbsp;和 <code>pop</code>&nbsp;的操作数不大于 <code>2 * 10<sup>4</sup></code>。</li>
	<li>输入保证在调用&nbsp;<code>pop</code>&nbsp;之前堆栈中至少有一个元素。</li>
</ul>


## 题解

### cpp [🔗](maximum-frequency-stack.cpp) 
```cpp
class FreqStack {
public:
    FreqStack() {
        max_freq_ = 0;
    }
    
    void push(int val) {
        int cntofval = 1 + freqs_[val];
        max_freq_ = std::max(max_freq_, cntofval);
        freqs_[val] = cntofval;
        stacks_[cntofval].push(val);
    }
    
    int pop() {
        if (stacks_[max_freq_].size() == 0) {
            throw "no value";
        }
        int top = stacks_[max_freq_].top();
        stacks_[max_freq_].pop();
        freqs_[top]--;
        if (stacks_[max_freq_].size() == 0) max_freq_--;
        return top;
    }
private:
    std::unordered_map<int, int> freqs_;
    std::unordered_map<int, std::stack<int>> stacks_;
    int max_freq_;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
```


## 相关话题

- [栈](../../tags/stack.md) 
- [设计](../../tags/design.md) 
- [哈希表](../../tags/hash-table.md) 
- [有序集合](../../tags/ordered-set.md) 


## 相似题目



## Links

- [Prev](../middle-of-the-linked-list/README.md) 
- [Next](../sort-array-by-parity/README.md) 

