
# [最近的请求次数](https://leetcode-cn.com/problems/number-of-recent-calls)

## 题目描述

<p>写一个&nbsp;<code>RecentCounter</code>&nbsp;类来计算特定时间范围内最近的请求。</p>

<p>请你实现 <code>RecentCounter</code> 类：</p>

<ul>
	<li><code>RecentCounter()</code> 初始化计数器，请求数为 0 。</li>
	<li><code>int ping(int t)</code> 在时间 <code>t</code> 添加一个新请求，其中 <code>t</code> 表示以毫秒为单位的某个时间，并返回过去 <code>3000</code> 毫秒内发生的所有请求数（包括新请求）。确切地说，返回在 <code>[t-3000, t]</code> 内发生的请求数。</li>
</ul>

<p><strong>保证</strong> 每次对 <code>ping</code> 的调用都使用比之前更大的 <code>t</code> 值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["RecentCounter", "ping", "ping", "ping", "ping"]
[[], [1], [100], [3001], [3002]]
<strong>输出：</strong>
[null, 1, 2, 3, 3]

<strong>解释：</strong>
RecentCounter recentCounter = new RecentCounter();
recentCounter.ping(1);     // requests = [<strong>1</strong>]，范围是 [-2999,1]，返回 1
recentCounter.ping(100);   // requests = [<strong>1</strong>, <strong>100</strong>]，范围是 [-2900,100]，返回 2
recentCounter.ping(3001);  // requests = [<strong>1</strong>, <strong>100</strong>, <strong>3001</strong>]，范围是 [1,3001]，返回 3
recentCounter.ping(3002);  // requests = [1, <strong>100</strong>, <strong>3001</strong>, <strong>3002</strong>]，范围是 [2,3002]，返回 3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= t &lt;= 10<sup>9</sup></code></li>
	<li>保证每次对 <code>ping</code> 调用所使用的 <code>t</code> 值都 <strong>严格递增</strong></li>
	<li>至多调用 <code>ping</code> 方法 <code>10<sup>4</sup></code> 次</li>
</ul>


## 题解

### golang [🔗](number-of-recent-calls.go) 
```golang
type RecentCounter struct {
    slice []int
}


func Constructor() RecentCounter {
    return RecentCounter {
        slice : make([]int, 0, 30000),
    }    
}


func (this *RecentCounter) Ping(t int) int {
    this.slice = append(this.slice, t)
    for this.slice[0] + 3000 < t {
        this.slice = this.slice[1:]
    }
    return len(this.slice)
}


/**
 * Your RecentCounter object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ping(t);
 */
```
### python3 [🔗](number-of-recent-calls.py) 
```python3
class RecentCounter:

    def __init__(self):
        from collections import deque
        self.q = deque()

    def ping(self, t: int) -> int:
        self.q.append(t)
        while self.q[0] + 3000 < t:
            self.q.popleft()

        return len(self.q)


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
```
### c [🔗](number-of-recent-calls.c) 
```c
typedef struct Node {
    struct Node* next;
    struct Node* pre;
    int time;
} Node;

typedef struct {
    struct Node* head;
    struct Node* tail;
    int size;
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter* c = (RecentCounter*)malloc(sizeof(RecentCounter));
    c->head = (Node*)malloc(sizeof(Node));
    c->tail = (Node*)malloc(sizeof(Node));
    c->head->pre = NULL;
    c->head->next = c->tail;
    c->tail->pre = c->head;
    c->tail->next = NULL;
    c->size = 0;
    return c;
}

int recentCounterPing(RecentCounter* obj, int t) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->time = t;
    node->pre = obj->tail->pre;
    node->next = obj->tail;
    obj->tail->pre->next = node;
    obj->tail->pre = node;
    obj->size++;

    while (obj->head->next->time + 3000 < t && obj->size != 0) {
        obj->size--;
        Node* dnode = obj->head->next;
        obj->head->next = dnode->next;
        dnode->next->pre = obj->head;
        free(dnode);
    }
    return obj->size;
}

void recentCounterFree(RecentCounter* obj) {
    while (obj->head->next != obj->tail) {
        Node* dnode = obj->head->next;
        obj->head->next = dnode->next;
        dnode->next->pre = obj->head;
        free(dnode);
    }
    free(obj->head);
    free(obj->tail);  
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/
```
### cpp [🔗](number-of-recent-calls.cpp) 
```cpp
class RecentCounter {
public:
    RecentCounter() {

    }
    
    int ping(int t) {
        t_queue_.push(t);
        while (t - t_queue_.front() > 3000) {
            t_queue_.pop();
        }
        return t_queue_.size();
    }
private:
    std::queue<int> t_queue_;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
```


## 相关话题

- [设计](../../tags/design.md) 
- [队列](../../tags/queue.md) 
- [数据流](../../tags/data-stream.md) 


## 相似题目



## Links

- [Prev](../unique-email-addresses/README.md) 
- [Next](../range-sum-of-bst/README.md) 

