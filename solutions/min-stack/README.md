
# [最小栈](https://leetcode-cn.com/problems/min-stack)

## 题目描述

<p>设计一个支持 <code>push</code> ，<code>pop</code> ，<code>top</code> 操作，并能在常数时间内检索到最小元素的栈。</p>

<p>实现 <code>MinStack</code> 类:</p>

<ul>
	<li><code>MinStack()</code> 初始化堆栈对象。</li>
	<li><code>void push(int val)</code> 将元素val推入堆栈。</li>
	<li><code>void pop()</code> 删除堆栈顶部的元素。</li>
	<li><code>int top()</code> 获取堆栈顶部的元素。</li>
	<li><code>int getMin()</code> 获取堆栈中的最小元素。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

<strong>输出：</strong>
[null,null,null,null,-3,null,0,-2]

<strong>解释：</strong>
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --&gt; 返回 -3.
minStack.pop();
minStack.top();      --&gt; 返回 0.
minStack.getMin();   --&gt; 返回 -2.
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-2<sup>31</sup>&nbsp;&lt;= val &lt;= 2<sup>31</sup>&nbsp;- 1</code></li>
	<li><code>pop</code>、<code>top</code> 和 <code>getMin</code> 操作总是在 <strong>非空栈</strong> 上调用</li>
	<li><code>push</code>,&nbsp;<code>pop</code>,&nbsp;<code>top</code>, and&nbsp;<code>getMin</code>最多被调用&nbsp;<code>3 * 10<sup>4</sup></code>&nbsp;次</li>
</ul>


## 题解

### golang [🔗](min-stack.go) 
```golang
type MinStack struct {
    data []int
}


func Constructor() MinStack {
    return MinStack {
        data : make([]int, 0, 512),
    }
}


func (this *MinStack) Push(val int)  {
    if len(this.data) == 0 {
        this.data = append(this.data, val, val)
    } else {
        min := this.GetMin()
        min = func(a, b int) int {
            if  a > b {
                return b
            }
            return a
        }(min, val)
        this.data = append(this.data, min, val)
    }
}


func (this *MinStack) Pop()  {
    dataSize := len(this.data)
    if dataSize < 2 {
        return
    }

    this.data = this.data[0: dataSize-2]
}


func (this *MinStack) Top() int {
    return this.data[len(this.data) - 1]
}


func (this *MinStack) GetMin() int {
    return this.data[len(this.data) - 2]
}


/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(val);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */
```
### cpp [🔗](min-stack.cpp) 
```cpp
class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        if (stack_.empty()) {
            stack_.push({val, val});
        } else {
            stack_.push({val, std::min(val, stack_.top().second)});
        }
    }
    
    void pop() {
        stack_.pop();
    }
    
    int top() {
        return stack_.top().first;
    }
    
    int getMin() {
        return stack_.top().second;
    }
private:
    std::stack<std::pair<int,int>> stack_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```


## 相关话题

- [栈](https://leetcode-cn.com/tag/stack) 
- [设计](https://leetcode-cn.com/tag/design) 


## 相似题目

- [滑动窗口最大值](../sliding-window-maximum/README.md)  [Hard] 
- [最大栈](../max-stack/README.md)  [Easy] 


## Links

- [Prev](../reverse-words-in-a-string/README.md) 
- [Next](../intersection-of-two-linked-lists/README.md) 

