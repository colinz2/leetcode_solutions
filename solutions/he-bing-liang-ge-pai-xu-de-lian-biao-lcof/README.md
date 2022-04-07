
# [](https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof)

## 题目描述



## 题解

### cpp [🔗](he-bing-liang-ge-pai-xu-de-lian-biao-lcof.cpp) 
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* l3 = &dummy;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                l3->next = l2;
                l2 = l2->next;
            } else {
                l3->next = l1;
                l1 = l1->next;
            }
            l3 = l3->next;
        }
        if (l1) {
            l3->next = l1;
        } else if (l2) {
            l3->next = l2;
        }
        return dummy.next;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../cong-wei-dao-tou-da-yin-lian-biao-lcof/README.md) 
- [Next](../er-jin-zhi-zhong-1de-ge-shu-lcof/README.md) 

