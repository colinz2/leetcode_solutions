
# [最大栈](https://leetcode-cn.com/problems/max-stack)

## 题目描述

<p>设计一个最大栈数据结构，既支持栈操作，又支持查找栈中最大元素。</p>

<p>实现 <code>MaxStack</code> 类：</p>

<ul>
	<li><code>MaxStack()</code> 初始化栈对象</li>
	<li><code>void push(int x)</code> 将元素 x 压入栈中。</li>
	<li><code>int pop()</code> 移除栈顶元素并返回这个元素。</li>
	<li><code>int top()</code> 返回栈顶元素，无需移除。</li>
	<li><code>int peekMax()</code> 检索并返回栈中最大元素，无需移除。</li>
	<li><code>int popMax()</code> 检索并返回栈中最大元素，并将其移除。如果有多个最大元素，只要移除 <strong>最靠近栈顶</strong> 的那个。</li>
</ul>

<p> </p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入</strong>
["MaxStack", "push", "push", "push", "top", "popMax", "top", "peekMax", "pop", "top"]
[[], [5], [1], [5], [], [], [], [], [], []]
<strong>输出</strong>
[null, null, null, null, 5, 5, 1, 5, 1, 5]

<strong>解释</strong>
MaxStack stk = new MaxStack();
stk.push(5);   // [<strong>5</strong>] - 5 既是栈顶元素，也是最大元素
stk.push(1);   // [<strong>5</strong>, <strong>1</strong>] - 栈顶元素是 1，最大元素是 5
stk.push(5);   // [5, 1, <strong>5</strong>] - 5 既是栈顶元素，也是最大元素
stk.top();     // 返回 5，[5, 1, <strong>5</strong>] - 栈没有改变
stk.popMax();  // 返回 5，[<strong>5</strong>, <strong>1</strong>] - 栈发生改变，栈顶元素不再是最大元素
stk.top();     // 返回 1，[<strong>5</strong>, <strong>1</strong>] - 栈没有改变
stk.peekMax(); // 返回 5，[<strong>5</strong>, <strong>1</strong>] - 栈没有改变
stk.pop();     // 返回 1，[<strong>5</strong>] - 此操作后，5 既是栈顶元素，也是最大元素
stk.top();     // 返回 5，[<strong>5</strong>] - 栈没有改变
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-10<sup>7</sup> <= x <= 10<sup>7</sup></code></li>
	<li>最多调用 <code>10<sup>4</sup></code> 次 <code>push</code>、<code>pop</code>、<code>top</code>、<code>peekMax</code> 和 <code>popMax</code></li>
	<li>调用 <code>pop</code>、<code>top</code>、<code>peekMax</code> 或 <code>popMax</code> 时，栈中 <strong>至少存在一个元素</strong></li>
</ul>

<p> </p>

<p><b>进阶：</b> </p>

<ul>
	<li>试着设计解决方案：调用 <code>top</code> 方法的时间复杂度为 <code>O(1)</code> ，调用其他方法的时间复杂度为 <code>O(logn)</code> 。 </li>
</ul>


## 题解

### cpp [🔗](max-stack.cpp) 
```cpp
class MaxStack {
public:
    MaxStack() {

    }
    
    void push(int x) {
        stack_.push(x);
        if (stack_max_.empty()) {
            stack_max_.push(x);
        } else {
            stack_max_.push(std::max(peekMax(), x));
        }
    }
    
    int pop() {
        int t = top();
        stack_.pop();
        stack_max_.pop();
        return t;
    }
    
    int top() {
        return stack_.top();
    }
    
    int peekMax() {
        return stack_max_.top();
    }
    
    // 这块很容易写错啊。
    int popMax() {
        int max = peekMax();
        std::stack<int> tmp;
        while (max != top()) {
            tmp.push(pop());
        }
        pop();
        while (!tmp.empty()) {
            push(tmp.top());
            tmp.pop();
        }
        return max;
    }
private:
    std::stack<int> stack_;
    std::stack<int> stack_max_;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
```


## 相关话题

- [栈](https://leetcode-cn.com/tag/stack) 
- [设计](https://leetcode-cn.com/tag/design) 
- [链表](https://leetcode-cn.com/tag/linked-list) 
- [双向链表](https://leetcode-cn.com/tag/doubly-linked-list) 
- [有序集合](https://leetcode-cn.com/tag/ordered-set) 


## 相似题目

- [最小栈](../min-stack/README.md)  [Easy] 


## Links

- [Prev](../minimum-ascii-delete-sum-for-two-strings/README.md) 
- [Next](../1-bit-and-2-bit-characters/README.md) 

