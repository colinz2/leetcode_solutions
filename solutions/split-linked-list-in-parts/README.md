
# [](https://leetcode-cn.com/problems/split-linked-list-in-parts)

## 题目描述



## 题解

### cpp [🔗](split-linked-list-in-parts.cpp) 
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k);
        if (head == nullptr) return res;
        int llen = 0;
        ListNode* curr = head;
        while (curr) {
            curr = curr->next;
            llen++;
        }
        
        ListNode* h = head;
        int plen = llen / k, rlen = llen % k;
        for (int i = 0; i < k; i++) {
            res[i] = h;
            for (int j = 1; j < plen +(i <rlen) && h; j++) {
                h = h->next;
            }
            if (h == nullptr) break;
            auto n = h->next;
            h->next = nullptr;
            h = n;
        }
        return res;
    }
};
```
### python3 [🔗](split-linked-list-in-parts.py) 
```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: ListNode, k: int) -> List[ListNode]:
        res = [None for _ in range(k)]
        if head == None:
            return res

        list_len = 0
        curr = head
        while curr:
            curr = curr.next
            list_len += 1
        psize = list_len // k
        rsize = list_len % k

        curr = head
        for i in range(k):
            if curr == None:
                break

            res[i] = curr        
            j = 1
            while j < psize + (1 if i < rsize else 0):
                curr = curr.next
                j += 1
            
            if curr:
                next_node = curr.next
                curr.next = None
                curr = next_node
        
        return res
```


## 相关话题



## 相似题目



## Links

- [Prev](../find-pivot-index/README.md) 
- [Next](../daily-temperatures/README.md) 

