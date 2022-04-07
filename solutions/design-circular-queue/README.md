
# [设计循环队列](https://leetcode-cn.com/problems/design-circular-queue)

## 题目描述

<p>设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为&ldquo;环形缓冲器&rdquo;。</p>

<p>循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。</p>

<p>你的实现应该支持如下操作：</p>

<ul>
	<li><code>MyCircularQueue(k)</code>: 构造器，设置队列长度为 k 。</li>
	<li><code>Front</code>: 从队首获取元素。如果队列为空，返回 -1 。</li>
	<li><code>Rear</code>: 获取队尾元素。如果队列为空，返回 -1 。</li>
	<li><code>enQueue(value)</code>: 向循环队列插入一个元素。如果成功插入则返回真。</li>
	<li><code>deQueue()</code>: 从循环队列中删除一个元素。如果成功删除则返回真。</li>
	<li><code>isEmpty()</code>: 检查循环队列是否为空。</li>
	<li><code>isFull()</code>: 检查循环队列是否已满。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>MyCircularQueue circularQueue = new MyCircularQueue(3); // 设置长度为 3
circularQueue.enQueue(1); &nbsp;// 返回 true
circularQueue.enQueue(2); &nbsp;// 返回 true
circularQueue.enQueue(3); &nbsp;// 返回 true
circularQueue.enQueue(4); &nbsp;// 返回 false，队列已满
circularQueue.Rear(); &nbsp;// 返回 3
circularQueue.isFull(); &nbsp;// 返回 true
circularQueue.deQueue(); &nbsp;// 返回 true
circularQueue.enQueue(4); &nbsp;// 返回 true
circularQueue.Rear(); &nbsp;// 返回 4</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>所有的值都在 0&nbsp;至 1000 的范围内；</li>
	<li>操作数将在 1 至 1000 的范围内；</li>
	<li>请不要使用内置的队列库。</li>
</ul>


## 题解

### cpp [🔗](design-circular-queue.cpp) 
```cpp
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        cap_ = k;
        read_index_ = 0;
        write_index_ = 0;
        data_.resize(cap_);
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        int index = write_index_++ % cap_;
        data_[index] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        read_index_++;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        int index = read_index_ % cap_;
        return data_[index];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        int index = (write_index_ - 1) % cap_;
        return data_[index];
    }
    
    bool isEmpty() {
        return read_index_ == write_index_;
    }
    
    bool isFull() {
        return write_index_ - read_index_ == cap_;
    }
private:
    int cap_;
    int read_index_;
    int write_index_;
    vector<int> data_;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
```


## 相关话题

- [设计](../../tags/design.md) 
- [队列](../../tags/queue.md) 
- [数组](../../tags/array.md) 
- [链表](../../tags/linked-list.md) 


## 相似题目



## Links

- [Prev](../insert-into-a-sorted-circular-linked-list/README.md) 
- [Next](../flipping-an-image/README.md) 

