
# [](https://leetcode-cn.com/problems/merge-two-binary-trees)

## 题目描述



## 题解

### cpp [🔗](merge-two-binary-trees.cpp) 
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* new_tr = NULL;
        if (t1 == NULL && t2 == NULL) {
            return NULL;
        } if (t1 != NULL && t2 != NULL) {
            t1->val += t2->val;
            new_tr = t1;
            new_tr->left = mergeTrees(t2->left, t1->left);
            new_tr->right = mergeTrees(t2->right, t1->right);
        } else if (t1) {
            new_tr = t1;
            new_tr->left = mergeTrees(t1->left, NULL);
            new_tr->right = mergeTrees(t1->right, NULL);
        } else {
            new_tr = t2;
            new_tr->left = mergeTrees(t2->left, NULL);
            new_tr->right = mergeTrees(t2->right, NULL);
        }
        return new_tr;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../construct-string-from-binary-tree/README.md) 
- [Next](../maximum-product-of-three-numbers/README.md) 

