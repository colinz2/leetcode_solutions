
# [用两个栈实现队列](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof)

## 题目描述

<p>用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 <code>appendTail</code> 和 <code>deleteHead</code> ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，<code>deleteHead</code>&nbsp;操作返回 -1 )</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>
[&quot;CQueue&quot;,&quot;appendTail&quot;,&quot;deleteHead&quot;,&quot;deleteHead&quot;]
[[],[3],[],[]]
<strong>输出：</strong>[null,null,3,-1]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>
[&quot;CQueue&quot;,&quot;deleteHead&quot;,&quot;appendTail&quot;,&quot;appendTail&quot;,&quot;deleteHead&quot;,&quot;deleteHead&quot;]
[[],[],[5],[2],[],[]]
<strong>输出：</strong>[null,-1,null,null,5,2]
</pre>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= values &lt;= 10000</code></li>
	<li><code>最多会对&nbsp;appendTail、deleteHead 进行&nbsp;10000&nbsp;次调用</code></li>
</ul>


## 题解

### golang [🔗](yong-liang-ge-zhan-shi-xian-dui-lie-lcof.go) 
```golang
type CQueue struct {
    a []int
    b []int
}


func Constructor() CQueue {
    return CQueue{}
}


func (this *CQueue) AppendTail(value int)  {
    this.a = append(this.a, value)
}


func (this *CQueue) DeleteHead() int {
    bLen := len(this.b)
    if len(this.a) + bLen == 0 {
        return -1
    }

    if bLen == 0 {
        bLen = len(this.a)
        for i := bLen - 1; i >= 0; i-- {
            this.b = append(this.b, this.a[i])
        }
        this.a = this.a[:0]
    }

    res := this.b[bLen - 1]
    this.b = this.b[:bLen - 1]
    return res
}


/**
 * Your CQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AppendTail(value);
 * param_2 := obj.DeleteHead();
 */
```
### cpp [🔗](yong-liang-ge-zhan-shi-xian-dui-lie-lcof.cpp) 
```cpp
class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        st1.push(value);
    }
    
    int deleteHead() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        if (st2.empty()) {
            return -1;
        }

        int top = st2.top();
        st2.pop();
        return top;
    }
private:
    stack<int> st1;
    stack<int> st2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```


## 相关话题

- [栈](../../tags/stack.md) 
- [设计](../../tags/design.md) 
- [队列](../../tags/queue.md) 


## 相似题目



## Links

- [Prev](../sum-lists-lcci/README.md) 
- [Next](../fei-bo-na-qi-shu-lie-lcof/README.md) 

