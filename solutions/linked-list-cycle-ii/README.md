
# [](https://leetcode-cn.com/problems/linked-list-cycle-ii)

## 题目描述



## 题解

### c [🔗](linked-list-cycle-ii.c) 
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    while (head) {
        if (head >= head->next) {
            return head->next;
        }
        head = head->next;
    }
    return NULL;
}
```
### cpp [🔗](linked-list-cycle-ii.cpp) 
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *f = head, *s = head;
        while (f && f->next) {
            f = f->next->next;
            s = s->next;
            if (f == s) {
                while (head != s) {
                    head = head->next;
                    s = s->next;
                }
                return head;
            }
        }
        return nullptr;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../linked-list-cycle/README.md) 
- [Next](../reorder-list/README.md) 

