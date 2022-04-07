
# [](https://leetcode-cn.com/problems/remove-linked-list-elements)

## 题目描述



## 题解

### c [🔗](remove-linked-list-elements.c) 
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode **list = &head;
    while (*list != NULL) {
        if ((*list)->val == val) {
            *list = (*list)->next;
        } else {
            list = &(*list)->next;
        }
    }
    return head;
}
```
### cpp [🔗](remove-linked-list-elements.cpp) 
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *curr = head;
        ListNode *pre = NULL;
        while (curr) {
            if (curr->val == val) {
                if (pre != NULL)
                    pre->next = curr->next;
                else 
                    head = head->next;
            } else {
                pre = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../happy-number/README.md) 
- [Next](../count-primes/README.md) 

