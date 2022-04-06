// @Title: Binary Search Tree Iterator
// @Author: colinjxc
// @Date: 2022-02-17T03:02:52+08:00
// @URL: https://leetcode-cn.com/problems/binary-search-tree-iterator


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



typedef struct {
    struct TreeNode* head;
} BSTIterator;

void inorder(BSTIterator* bst_iter, struct TreeNode* root) {
    if (root == NULL) return;
    inorder(bst_iter, root->right);
    root->right = bst_iter->head->right;
    bst_iter->head->right = root;
    inorder(bst_iter, root->left);
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* bst_iter = malloc(sizeof(BSTIterator));
    bst_iter->head = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    bst_iter->head->left = NULL;
    bst_iter->head->right = NULL;

    inorder(bst_iter, root);
    return bst_iter;
}

int bSTIteratorNext(BSTIterator* obj) {
    if (obj->head->right == NULL) {
        return -1;
    }
    int ret = obj->head->right->val;
    // for free
    obj->head->right->left = obj->head->left;
    obj->head->left = obj->head->right;

    obj->head->right = obj->head->right->right;
    return ret;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->head->right != NULL;
}

void bSTIteratorFree(BSTIterator* obj) {
    if (obj) {
        while (obj->head->left) {
            struct TreeNode* f = obj->head->left;
            obj->head->left = obj->head->left->left;
            free(f);
        }
        free(obj->head);
        free(obj);
    }
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/
