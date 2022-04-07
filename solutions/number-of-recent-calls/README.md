
# [](https://leetcode-cn.com/problems/number-of-recent-calls)

## 题目描述



## 题解

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


## 相关话题



## 相似题目



## Links

- [Prev](../unique-email-addresses/README.md) 
- [Next](../range-sum-of-bst/README.md) 

