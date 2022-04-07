
# [](https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof)

## 题目描述



## 题解

### cpp [🔗](fan-zhuan-lian-biao-lcof.cpp) 
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
    ListNode* reverseList(ListNode* head) {
        ListNode* newNode = NULL;
        while (head != NULL) {
            ListNode* next = head->next;
            head->next = newNode;
            newNode = head;
            head = next;
        }
        return newNode;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/README.md) 
- [Next](../shan-chu-lian-biao-de-jie-dian-lcof/README.md) 

