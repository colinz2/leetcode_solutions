
# [设计有限阻塞队列](https://leetcode-cn.com/problems/design-bounded-blocking-queue)

## 题目描述

<p>实现一个拥有如下方法的线程安全有限阻塞队列：</p>

<ul>
	<li><code>BoundedBlockingQueue(int capacity)</code>&nbsp;构造方法初始化队列，其中<code>capacity</code>代表队列长度上限。</li>
	<li><code>void enqueue(int element)</code>&nbsp;在队首增加一个<code>element</code>. 如果队列满，调用线程被阻塞直到队列非满。</li>
	<li><code>int dequeue()</code>&nbsp;返回队尾元素并从队列中将其删除. 如果队列为空，调用线程被阻塞直到队列非空。</li>
	<li><code>int size()</code>&nbsp;返回当前队列元素个数。</li>
</ul>

<p>你的实现将会被多线程同时访问进行测试。每一个线程要么是一个只调用<code>enqueue</code>方法的生产者线程，要么是一个只调用<code>dequeue</code>方法的消费者线程。<code>size</code>方法将会在每一个测试用例之后进行调用。</p>

<p>请不要使用内置的有限阻塞队列实现，否则面试将不会通过。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong>
1
1
["BoundedBlockingQueue","enqueue","dequeue","dequeue","enqueue","enqueue","enqueue","enqueue","dequeue"]
[[2],[1],[],[],[0],[2],[3],[4],[]]

<strong>输出:</strong>
[1,0,2,2]

<strong>解释:
</strong>生产者线程数目 = 1
消费者线程数目 = 1

BoundedBlockingQueue queue = new BoundedBlockingQueue(2);   // 使用capacity = 2初始化队列。

queue.enqueue(1);   // 生产者线程将 1 插入队列。
queue.dequeue();    // 消费者线程调用 dequeue 并返回 1 。
queue.dequeue();    // 由于队列为空，消费者线程被阻塞。
queue.enqueue(0);   // 生产者线程将 0 插入队列。消费者线程被解除阻塞同时将 0 弹出队列并返回。
queue.enqueue(2);   // 生产者线程将 2 插入队列。
queue.enqueue(3);   // 生产者线程将 3 插入队列。
queue.enqueue(4);   // 生产者线程由于队列长度已达到上限 2 而被阻塞。
queue.dequeue();    // 消费者线程将 2 从队列弹出并返回。生产者线程解除阻塞同时将4插入队列。
queue.size();       // 队列中还有 2 个元素。size()方法在每组测试用例最后调用。
</pre>

<p>&nbsp;</p>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong>
3
4
["BoundedBlockingQueue","enqueue","enqueue","enqueue","dequeue","dequeue","dequeue","enqueue"]
[[3],[1],[0],[2],[],[],[],[3]]

<strong>输出:</strong>
[1,0,2,1]

<strong>解释:
</strong>生产者线程数目 = 3
消费者线程数目 = 4

BoundedBlockingQueue queue = new BoundedBlockingQueue(3);   // 使用capacity = 3初始化队列。

queue.enqueue(1);   // 生产者线程 P1 将 1 插入队列。
queue.enqueue(0);   // 生产者线程 P2 将 0 插入队列。
queue.enqueue(2);   // 生产者线程 P3 将2插入队列。
queue.dequeue();    // 消费者线程 C1 调用 dequeue。
queue.dequeue();    // 消费者线程 C2 调用 dequeue。
queue.dequeue();    // 消费者线程 C3 调用 dequeue。
queue.enqueue(3);   // 其中一个生产者线程将3插入队列。
queue.size();       // 队列中还有 1 个元素。

由于生产者/消费者线程的数目可能大于 1 ，我们并不知道线程如何被操作系统调度，即使输入看上去隐含了顺序。因此任意一种输出[1,0,2]或[1,2,0]或[0,1,2]或[0,2,1]或[2,0,1]或[2,1,0]都可被接受。</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= Number of Prdoucers &lt;= 8</code></li>
	<li><code>1 &lt;= Number of Consumers &lt;= 8</code></li>
	<li><code>1 &lt;= size &lt;= 30</code></li>
	<li><code>0 &lt;= element &lt;= 20</code></li>
	<li>&nbsp;<code>enqueue</code>的调用次数&nbsp;<strong>大于等于</strong> &nbsp;<code>dequeue</code>&nbsp;的调用次数。</li>
	<li>&nbsp;<code>enque</code>,&nbsp;<code>deque</code> 和&nbsp;<code>size</code>&nbsp;最多被调用&nbsp;<code>40</code>&nbsp;次</li>
</ul>


## 题解

### cpp [🔗](design-bounded-blocking-queue.cpp) 
```cpp
class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity) {
        cap_ = capacity;
    }
    
    void enqueue(int element) {
        std::unique_lock<std::mutex> lock(mutex_);
        
        cv_.wait(lock, [this](){ return queue_.size() < cap_; });
        queue_.push(element);
        lock.unlock();

        cv_.notify_all();
    }
    
    int dequeue() {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this](){ return !queue_.empty(); });

        auto head = queue_.front();
        queue_.pop();
        lock.unlock();

        cv_.notify_all();
        return head;
    }
    
    int size() {
        std::unique_lock<std::mutex> lock(mutex_);
        auto size = queue_.size();
        lock.unlock();
        return size;
    }
private:
    int cap_;
    std::queue<int> queue_;
    std::mutex mutex_;
    std::condition_variable cv_;
};
```


## 相关话题

- [多线程](../../tags/concurrency.md) 


## 相似题目



## Links

- [Prev](../print-in-order/README.md) 
- [Next](../print-zero-even-odd/README.md) 

