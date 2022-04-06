// @Title: Design Linked List
// @Author: colinjxc
// @Date: 2022-02-04T12:45:47+08:00
// @URL: https://leetcode-cn.com/problems/design-linked-list


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
