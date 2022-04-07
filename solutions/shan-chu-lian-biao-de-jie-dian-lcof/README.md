
# [](https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof)

## 题目描述



## 题解

### c [🔗](shan-chu-lian-biao-de-jie-dian-lcof.c) 
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteNode(struct ListNode* head, int val){
    struct ListNode dummy = {.next = head};
    struct ListNode* prev = &dummy;
    while (head) {
        if (head->val == val) {
            prev->next = head->next;
            free(head);
            head = prev->next;
        } else {
            prev = head;
            head = head->next;
        }
    }
    return dummy.next;
}
```


## 相关话题



## 相似题目



## Links

- [Prev](../fan-zhuan-lian-biao-lcof/README.md) 
- [Next](../zui-xiao-de-kge-shu-lcof/README.md) 

