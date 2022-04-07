
# [](https://leetcode-cn.com/problems/binary-tree-postorder-traversal)

## 题目描述



## 题解

### cpp [🔗](binary-tree-postorder-traversal.cpp) 
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;

        stack<TreeNode*> stack, output;

        TreeNode* p = root;
        while (p != NULL || !stack.empty()) {
            if (p != NULL) {
                stack.push(p);
                output.push(p);
                p = p->right;
            } else {
                p = stack.top();
                stack.pop();
                p = p->left;
            }
        }

        while (!output.empty()) {
            res.push_back((output.top())->val);
            output.pop();
        }
        return res;
    }
};

```


## 相关话题



## 相似题目



## Links

- [Prev](../binary-tree-preorder-traversal/README.md) 
- [Next](../lru-cache/README.md) 

