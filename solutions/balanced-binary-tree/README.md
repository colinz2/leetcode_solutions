
# [](https://leetcode-cn.com/problems/balanced-binary-tree)

## 题目描述



## 题解

### cpp [🔗](balanced-binary-tree.cpp) 
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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        return abs(hight(left) - hight(right)) <= 1 && isBalanced(left) && isBalanced(right); 
    }

    int hight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return std::max(hight(root->left), hight(root->right)) + 1;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../convert-sorted-list-to-binary-search-tree/README.md) 
- [Next](../minimum-depth-of-binary-tree/README.md) 

