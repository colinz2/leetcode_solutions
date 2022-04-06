
# [设计链表](https://leetcode-cn.com/problems/design-linked-list)

## 题目描述

<p>设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：<code>val</code>&nbsp;和&nbsp;<code>next</code>。<code>val</code>&nbsp;是当前节点的值，<code>next</code>&nbsp;是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性&nbsp;<code>prev</code>&nbsp;以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。</p>

<p>在链表类中实现这些功能：</p>

<ul>
	<li>get(index)：获取链表中第&nbsp;<code>index</code>&nbsp;个节点的值。如果索引无效，则返回<code>-1</code>。</li>
	<li>addAtHead(val)：在链表的第一个元素之前添加一个值为&nbsp;<code>val</code>&nbsp;的节点。插入后，新节点将成为链表的第一个节点。</li>
	<li>addAtTail(val)：将值为&nbsp;<code>val</code> 的节点追加到链表的最后一个元素。</li>
	<li>addAtIndex(index,val)：在链表中的第&nbsp;<code>index</code>&nbsp;个节点之前添加值为&nbsp;<code>val</code>&nbsp; 的节点。如果&nbsp;<code>index</code>&nbsp;等于链表的长度，则该节点将附加到链表的末尾。如果 <code>index</code> 大于链表长度，则不会插入节点。如果<code>index</code>小于0，则在头部插入节点。</li>
	<li>deleteAtIndex(index)：如果索引&nbsp;<code>index</code> 有效，则删除链表中的第&nbsp;<code>index</code> 个节点。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1,2);   //链表变为1-&gt; 2-&gt; 3
linkedList.get(1);            //返回2
linkedList.deleteAtIndex(1);  //现在链表是1-&gt; 3
linkedList.get(1);            //返回3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>所有<code>val</code>值都在&nbsp;<code>[1, 1000]</code>&nbsp;之内。</li>
	<li>操作次数将在&nbsp;&nbsp;<code>[1, 1000]</code>&nbsp;之内。</li>
	<li>请不要使用内置的 LinkedList 库。</li>
</ul>


## 题解

### cpp [🔗](design-linked-list.cpp) 
```cpp
class MyLinkedList {
public:
    MyLinkedList() {
        root_ = new ListNode(-999);
        root_->prev = root_;
        root_->next = root_;
    }
    
    int get(int index) {
        if (index < 0) return -1;
        ListNode* tmp = root_->next;
        for (int i = 0; tmp != root_ ; i++) {
            if (i == index) return tmp->val;
            tmp = tmp->next;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        ListNode* node = new ListNode(val, root_, root_->next);
        root_->next->prev = node;
        root_->next = node; 
    }
    
    void addAtTail(int val) {
        ListNode* node = new ListNode(val, root_->prev, root_);
        root_->prev->next = node;
        root_->prev = node;
    }
    
    void addAtIndex(int index, int val) {
        if (index <= 0) {
            return addAtHead(val);
        } else if (index > 0 && isEmpty()) {
            return;
        }
        ListNode* tmp = root_->next;
        for (int i = 0; i <= index; i++, tmp = tmp->next) {
            if (tmp == root_ && i < index) {
                break;
            }
            if (i == index) {
                ListNode* node = new ListNode(val, tmp->prev, tmp);
                tmp->prev->next = node;
                tmp->prev = node;
                break;
            }
        }
    }
    
    void deleteAtIndex(int index) {
        ListNode* tmp = root_->next;
        for (int i = 0; tmp != root_ && i <= index; tmp = tmp->next, i++) {
            if (i == index) {
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                delete tmp;
                break;
            }
        }
    }
    bool isEmpty() {
        return root_->next == root_;
    }
public:
    template<typename T>
    struct Node {
        Node<T>* prev;
        Node<T>* next;
        T val;

        Node(T v) : val(v) {};
        Node(T v, Node<T>* p, Node<T>* n) : prev(p), next(n), val(v) {};
    };
    using ListNode = Node<int>;
private:
    ListNode* root_;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
```


## 相关话题

- [设计](https://leetcode-cn.com/tag/design) 
- [链表](https://leetcode-cn.com/tag/linked-list) 


## 相似题目



## Links

- [Prev](../most-common-word/README.md) 
- [Next](../insert-into-a-sorted-circular-linked-list/README.md) 

