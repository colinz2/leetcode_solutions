
# [](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof)

## 题目描述



## 题解

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


## 相关话题



## 相似题目



## Links

- [Prev](../sum-lists-lcci/README.md) 
- [Next](../fei-bo-na-qi-shu-lie-lcof/README.md) 

