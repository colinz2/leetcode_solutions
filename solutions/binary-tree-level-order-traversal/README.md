
# [二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal)

## 题目描述

<p>给你一个二叉树，请你返回其按 <strong>层序遍历</strong> 得到的节点值。 （即逐层地，从左到右访问所有节点）。</p>

<p> </p>

<p><strong>示例：</strong><br />
二叉树：<code>[3,9,20,null,null,15,7]</code>,</p>

<pre>
    3
   / \
  9  20
    /  \
   15   7
</pre>

<p>返回其层序遍历结果：</p>

<pre>
[
  [3],
  [9,20],
  [15,7]
]
</pre>


## 题解

### cpp [🔗](binary-tree-level-order-traversal.cpp) 
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root == nullptr) return res;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            res.push_back(vector<int>());
            for (int i = 0; i < levelSize; i++) {
                auto node = q.front(); q.pop();
                res.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
};
```


## 相关话题

- [树](https://leetcode-cn.com/tag/tree) 
- [广度优先搜索](https://leetcode-cn.com/tag/breadth-first-search) 
- [二叉树](https://leetcode-cn.com/tag/binary-tree) 


## 相似题目

- [二叉树的层序遍历 II](../binary-tree-level-order-traversal-ii/README.md)  [Medium] 
- [二叉树的最小深度](../minimum-depth-of-binary-tree/README.md)  [Easy] 
- [二叉树的层平均值](../average-of-levels-in-binary-tree/README.md)  [Easy] 


## Links

- [Prev](../search-insert-position/README.md) 
- [Next](../maximum-depth-of-binary-tree/README.md) 

