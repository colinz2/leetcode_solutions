
# [](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list)

## 题目描述



## 题解

### cpp [🔗](remove-duplicates-from-sorted-list.cpp) 
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while (curr) {
            if (curr->next == nullptr) break;

            if (curr->val == curr->next->val) {
                ListNode* d = curr->next;
                curr->next = curr->next->next;
                delete d;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../remove-duplicates-from-sorted-list-ii/README.md) 
- [Next](../largest-rectangle-in-histogram/README.md) 

