
# [](https://leetcode-cn.com/problems/merge-two-sorted-lists)

## 题目描述



## 题解

### cpp [🔗](merge-two-sorted-lists.cpp) 
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* l3 = &dummy;
        while (list1 && list2) {
            if (list1->val > list2->val) {
                l3->next = list2;
                list2 = list2->next;
            } else {
                l3->next = list1;
                list1 = list1->next;
            }
            l3 = l3->next;
        }
        if (list1) {
            l3->next = list1;
        } else {
            l3->next = list2;
        }

        return dummy.next;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../valid-parentheses/README.md) 
- [Next](../generate-parentheses/README.md) 

