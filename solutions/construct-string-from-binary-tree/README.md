
# [](https://leetcode-cn.com/problems/construct-string-from-binary-tree)

## 题目描述



## 题解

### cpp [🔗](construct-string-from-binary-tree.cpp) 
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
    string tree2str(TreeNode* root) {
        string res;
        std::function<void(TreeNode*)> preorder = [&](TreeNode* node) {
            if (node == nullptr) return;
            res += std::to_string(node->val);
            if (node->left != nullptr || node->right != nullptr) {
                res += "(";
                preorder(node->left);
                res += ")";
            }
            if (node->right != nullptr ) {
                res += "(";
                preorder(node->right);
                res += ")";
            }
        };

        preorder(root);
        return res;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../design-compressed-string-iterator/README.md) 
- [Next](../merge-two-binary-trees/README.md) 

