
# [用队列实现栈](https://leetcode-cn.com/problems/implement-stack-using-queues)

## 题目描述

<p>请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（<code>push</code>、<code>top</code>、<code>pop</code> 和 <code>empty</code>）。</p>

<p>实现 <code>MyStack</code> 类：</p>

<ul>
	<li><code>void push(int x)</code> 将元素 x 压入栈顶。</li>
	<li><code>int pop()</code> 移除并返回栈顶元素。</li>
	<li><code>int top()</code> 返回栈顶元素。</li>
	<li><code>boolean empty()</code> 如果栈是空的，返回 <code>true</code> ；否则，返回 <code>false</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong></p>

<ul>
	<li>你只能使用队列的基本操作 —— 也就是&nbsp;<code>push to back</code>、<code>peek/pop from front</code>、<code>size</code> 和&nbsp;<code>is empty</code>&nbsp;这些操作。</li>
	<li>你所使用的语言也许不支持队列。&nbsp;你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列&nbsp;, 只要是标准的队列操作即可。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
<strong>输出：</strong>
[null, null, null, 2, 2, false]

<strong>解释：</strong>
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // 返回 2
myStack.pop(); // 返回 2
myStack.empty(); // 返回 False
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= x &lt;= 9</code></li>
	<li>最多调用<code>100</code> 次 <code>push</code>、<code>pop</code>、<code>top</code> 和 <code>empty</code></li>
	<li>每次调用 <code>pop</code> 和 <code>top</code> 都保证栈不为空</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能否仅用一个队列来实现栈。</p>


## 题解

### cpp [🔗](implement-stack-using-queues.cpp) 
```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        list_.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = list_.back();
        list_.pop_back();
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return list_.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return list_.empty();
    }
private:
    list<int> list_;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```
### golang [🔗](implement-stack-using-queues.go) 
```golang
type MyStack struct {
    Stack []int
}


/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{
        Stack: make([]int, 0, 100),
    }
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    this.Stack = append(this.Stack, x)
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    top := this.Top()
    this.Stack = this.Stack[:len(this.Stack) - 1]
    return top
}


/** Get the top element. */
func (this *MyStack) Top() int {
    return this.Stack[len(this.Stack) - 1]
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    return len(this.Stack) == 0
}


/**
 * Your MyStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Empty();
 */
```


## 相关话题

- [栈](../../tags/stack.md) 
- [设计](../../tags/design.md) 
- [队列](../../tags/queue.md) 


## 相似题目

- [用栈实现队列](../implement-queue-using-stacks/README.md)  [Easy] 


## Links

- [Prev](../maximal-square/README.md) 
- [Next](../invert-binary-tree/README.md) 

