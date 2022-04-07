
# [](https://leetcode-cn.com/problems/invert-binary-tree)

## 题目描述



## 题解

### cpp [🔗](invert-binary-tree.cpp) 
```cpp
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            std::swap(node->right, node->left);
            if (node->right) q.push(node->right);
            if (node->left) q.push(node->left);
        }
        return root;
    }
};
```
### c [🔗](invert-binary-tree.c) 
```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root){
    if (root == NULL) return root;
    invertTree(root->left);
    invertTree(root->right);
    struct TreeNode* tmp;
    tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    return root;
}
```


## 相关话题



## 相似题目



## Links

- [Prev](../implement-stack-using-queues/README.md) 
- [Next](../summary-ranges/README.md) 

