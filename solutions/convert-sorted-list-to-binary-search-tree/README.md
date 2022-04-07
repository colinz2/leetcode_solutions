
# [](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree)

## 题目描述



## 题解

### c [🔗](convert-sorted-list-to-binary-search-tree.c) 
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* sortedListToBST(struct ListNode* head){
    if (head == NULL) return NULL;
    struct ListNode *fast = head, *slow = head;
    struct ListNode** preSlow = &head;
    
    while (fast && fast->next) {
        fast = fast->next->next;
        preSlow = &(slow->next);
        slow = slow->next;
    }

    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = slow->val;
    *preSlow = NULL;
    node->left = sortedListToBST(head);
    node->right = sortedListToBST(slow->next);
    return  node;
}
```
### cpp [🔗](convert-sorted-list-to-binary-search-tree.cpp) 
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortListToBST(head, nullptr);
    }   

    TreeNode* sortListToBST(ListNode* head, ListNode* tail) {
        if (head == tail) {
            return nullptr;
        }
        ListNode* mid = head;
        ListNode* fast = head;
        while (fast != tail && fast->next != tail) {
            fast = fast->next->next;
            mid = mid->next;
        }
        TreeNode* node = new TreeNode(mid->val);
        node->left = sortListToBST(head, mid);
        node->right = sortListToBST(mid->next, tail);
        return node;
    }
};






```


## 相关话题



## 相似题目



## Links

- [Prev](../convert-sorted-array-to-binary-search-tree/README.md) 
- [Next](../balanced-binary-tree/README.md) 

