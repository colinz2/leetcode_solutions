
# [](https://leetcode-cn.com/problems/reverse-nodes-in-k-group)

## 题目描述



## 题解

### cpp [🔗](reverse-nodes-in-k-group.cpp) 
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int list_len = 0;
        ListNode dummy;
        dummy.next = head;
        while (head) {
            head = head->next;
            list_len++;
        }

        ListNode* pre = &dummy;
        head = dummy.next;
        for (int i = 0; i < list_len / k; i++) {
            for (int j = 1; j < k; j++) {
                auto next = head->next;
                head->next = head->next->next;
                next->next = pre->next;
                pre->next = next;
            }
            pre = head;
            head = head->next;
        }

        return dummy.next;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../swap-nodes-in-pairs/README.md) 
- [Next](../remove-duplicates-from-sorted-array/README.md) 

