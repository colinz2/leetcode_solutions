
# [](https://leetcode-cn.com/problems/merge-k-sorted-lists)

## 题目描述



## 题解

### cpp [🔗](merge-k-sorted-lists.cpp) 
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class CompareListNode{
public:
    bool operator()(ListNode* node1, ListNode* node2){
        return node1->val > node2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;

        ListNode* dummyHead = new ListNode(-1);
        ListNode* curNode = dummyHead;

        priority_queue<ListNode*, vector<ListNode*>, CompareListNode> q;
        for(ListNode* node: lists)
            if(node != NULL)
                q.push(node);

        while(!q.empty()){

            ListNode* nextNode = q.top();
            q.pop();


            curNode->next = nextNode;
            if(nextNode->next != NULL)
                q.push(nextNode->next);

            nextNode->next = NULL;
            curNode = curNode->next;
        }

        ListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../generate-parentheses/README.md) 
- [Next](../swap-nodes-in-pairs/README.md) 

