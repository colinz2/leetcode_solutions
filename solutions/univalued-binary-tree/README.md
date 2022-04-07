
# [](https://leetcode-cn.com/problems/univalued-binary-tree)

## 题目描述



## 题解

### cpp [🔗](univalued-binary-tree.cpp) 
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
    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        std::stack<TreeNode*> stk;
        int target = root->val;
        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (root->val != target) {
                return false;
            }
            root = root->right;
        }
        return true;
    }
};
```
### golang [🔗](univalued-binary-tree.go) 
```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isUnivalTree(root *TreeNode) bool {
    if root == nil {
        return true
    }
    return dfsCheck(root, root.Val)
}

func dfsCheck(root *TreeNode, val int) bool {
    if root == nil {
        return true
    }
    if root.Val != val {
        return false
    }
    return dfsCheck(root.Left, val) && dfsCheck(root.Right, val)
}
```


## 相关话题



## 相似题目



## Links

- [Prev](../range-sum-of-bst/README.md) 
- [Next](../fibonacci-number/README.md) 

