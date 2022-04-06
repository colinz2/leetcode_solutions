// @Title: Populating Next Right Pointers in Each Node
// @Author: colinjxc
// @Date: 2022-02-05T00:11:34+08:00
// @URL: https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node


/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
    if (root == NULL) return NULL;
    // 只有非叶子节点才可以这样做。
    if (root->left) {
        root->left->next = root->right;
        if (root->next) {
            root->right->next = root->next->left;
        }
    }
    connect(root->left);
    connect(root->right);
    return root;
}
