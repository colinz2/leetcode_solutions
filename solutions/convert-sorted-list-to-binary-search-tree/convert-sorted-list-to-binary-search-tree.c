// @Title: Convert Sorted List to Binary Search Tree
// @Author: colinjxc
// @Date: 2022-02-03T00:47:55+08:00
// @URL: https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree


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
