
# [二叉树的层平均值](https://leetcode-cn.com/problems/average-of-levels-in-binary-tree)

## 题目描述

<p>给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>
    3
   / \
  9  20
    /  \
   15   7
<strong>输出：</strong>[3, 14.5, 11]
<strong>解释：</strong>
第 0 层的平均值是 3 ,  第1层是 14.5 , 第2层是 11 。因此返回 [3, 14.5, 11] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>节点值的范围在32位有符号整数范围内。</li>
</ul>


## 题解

### cpp [🔗](average-of-levels-in-binary-tree.cpp) 
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;

        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            double sum = 0.0;
            for (int i =  0; i < levelSize; i++) {
                auto node = q.front(); q.pop();
                sum += (double)node->val; 
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(sum / levelSize);
        }

        return res;
    }
};
```


## 相关话题

- [树](https://leetcode-cn.com/tag/tree) 
- [深度优先搜索](https://leetcode-cn.com/tag/depth-first-search) 
- [广度优先搜索](https://leetcode-cn.com/tag/breadth-first-search) 
- [二叉树](https://leetcode-cn.com/tag/binary-tree) 


## 相似题目

- [二叉树的层序遍历](../binary-tree-level-order-traversal/README.md)  [Medium] 
- [二叉树的层序遍历 II](../binary-tree-level-order-traversal-ii/README.md)  [Medium] 


## Links

- [Prev](../number-of-provinces/README.md) 
- [Next](../redundant-connection/README.md) 

