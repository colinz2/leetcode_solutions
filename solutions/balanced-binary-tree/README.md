
# [平衡二叉树](https://leetcode-cn.com/problems/balanced-binary-tree)

## 题目描述

<p>给定一个二叉树，判断它是否是高度平衡的二叉树。</p>

<p>本题中，一棵高度平衡二叉树定义为：</p>

<blockquote>
<p>一个二叉树<em>每个节点 </em>的左右两个子树的高度差的绝对值不超过 1 。</p>
</blockquote>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/06/balance_1.jpg" style="width: 342px; height: 221px;" />
<pre>
<strong>输入：</strong>root = [3,9,20,null,null,15,7]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/06/balance_2.jpg" style="width: 452px; height: 301px;" />
<pre>
<strong>输入：</strong>root = [1,2,2,3,3,null,null,4,4]
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = []
<strong>输出：</strong>true
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数在范围 <code>[0, 5000]</code> 内</li>
	<li><code>-10<sup>4</sup> <= Node.val <= 10<sup>4</sup></code></li>
</ul>


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

- [树](../../tags/tree.md) 
- [深度优先搜索](../../tags/depth-first-search.md) 
- [二叉树](../../tags/binary-tree.md) 


## 相似题目

- [二叉树的最大深度](../maximum-depth-of-binary-tree/README.md)  [Easy] 


## Links

- [Prev](../convert-sorted-list-to-binary-search-tree/README.md) 
- [Next](../minimum-depth-of-binary-tree/README.md) 

