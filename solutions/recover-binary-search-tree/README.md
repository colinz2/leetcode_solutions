
# [](https://leetcode-cn.com/problems/recover-binary-search-tree)

## 题目描述



## 题解

### c [🔗](recover-binary-search-tree.c) 
```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *prev;
struct TreeNode *first;
struct TreeNode *last;

void inorder(struct TreeNode* root) {
    if (root == NULL) {
        return root;
    }
    inorder(root->left);
    if (prev != NULL) {
        if (prev->val > root->val) {
            if (first == NULL) {
                first = prev;
            }
            last = root;
        }
    }
    prev = root;
    inorder(root->right);
}

void recoverTree(struct TreeNode* root){
    if (root == NULL) {
        return;
    }
    prev = NULL, first = NULL, last = NULL;
    inorder(root);
    if (first != NULL && last != NULL) {
        int val = first->val;
        first->val = last->val;
        last->val = val;
    }
}

```


## 相关话题



## 相似题目



## Links

- [Prev](../validate-binary-search-tree/README.md) 
- [Next](../same-tree/README.md) 

