
# [最小栈](https://leetcode-cn.com/problems/min-stack)

## 题目描述

<p>设计一个支持 <code>push</code> ，<code>pop</code> ，<code>top</code> 操作，并能在常数时间内检索到最小元素的栈。</p>

<ul>
	<li><code>push(x)</code> &mdash;&mdash; 将元素 x 推入栈中。</li>
	<li><code>pop()</code>&nbsp;&mdash;&mdash; 删除栈顶的元素。</li>
	<li><code>top()</code>&nbsp;&mdash;&mdash; 获取栈顶元素。</li>
	<li><code>getMin()</code> &mdash;&mdash; 检索栈中的最小元素。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例:</strong></p>

<pre><strong>输入：</strong>
[&quot;MinStack&quot;,&quot;push&quot;,&quot;push&quot;,&quot;push&quot;,&quot;getMin&quot;,&quot;pop&quot;,&quot;top&quot;,&quot;getMin&quot;]
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
	<li><code>pop</code>、<code>top</code> 和 <code>getMin</code> 操作总是在 <strong>非空栈</strong> 上调用。</li>
</ul>


## 题解

### cpp [🔗](min-stack.cpp) 
```cpp
class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        if (stack_.empty()) {
            stack_.push({val, val});
            return;
        }
        int min = getMin();
        min = std::min(min, val);
        stack_.push({val, min});
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
    stack<pair<int, int>> stack_;
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


## 相关话题

- [栈](https://leetcode-cn.com/tag/stack) 
- [设计](https://leetcode-cn.com/tag/design) 


## 相似题目



## Links

- [Prev](../best-time-to-buy-and-sell-stock-ii/README.md) 
- [Next](../reverse-bits/README.md) 

