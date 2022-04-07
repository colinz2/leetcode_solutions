
# [](https://leetcode-cn.com/problems/reverse-linked-list-ii)

## 题目描述



## 题解

### c [🔗](reverse-linked-list-ii.c) 
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode dummy = {.next = head};
    struct ListNode *curr = head, *pre = &dummy, *next;
    int index = 0;
    while (curr) {
        if (++index >= left && index < right) {
            next = curr->next;
            curr->next = next->next;
            next->next = pre->next;
            pre->next = next;
        } else {
            pre = curr;
            curr = curr->next;
        }
    }
    return dummy.next;
}
```
### cpp [🔗](reverse-linked-list-ii.cpp) 
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;

        for (int i = 0; i < left - 1; ++i) {
            pre = pre->next;
        }
        ListNode *curr = pre->next;
        for (int i = left; i < right; ++i) {
            ListNode *t = curr->next;
            curr->next = t->next;
            t->next = pre->next;
            pre->next = t;
        }
        return dummy->next;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../subsets-ii/README.md) 
- [Next](../restore-ip-addresses/README.md) 

