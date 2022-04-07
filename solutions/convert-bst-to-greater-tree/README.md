
# [把二叉搜索树转换为累加树](https://leetcode-cn.com/problems/convert-bst-to-greater-tree)

## 题目描述

<p>给出二叉<strong> 搜索 </strong>树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 <code>node</code>&nbsp;的新值等于原树中大于或等于&nbsp;<code>node.val</code>&nbsp;的值之和。</p>

<p>提醒一下，二叉搜索树满足下列约束条件：</p>

<ul>
	<li>节点的左子树仅包含键<strong> 小于 </strong>节点键的节点。</li>
	<li>节点的右子树仅包含键<strong> 大于</strong> 节点键的节点。</li>
	<li>左右子树也必须是二叉搜索树。</li>
</ul>

<p><strong>注意：</strong>本题和 1038:&nbsp;<a href="https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/">https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/</a> 相同</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/05/03/tree.png" style="height: 364px; width: 534px;"></strong></p>

<pre><strong>输入：</strong>[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
<strong>输出：</strong>[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>root = [0,null,1]
<strong>输出：</strong>[1,null,1]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>root = [1,0,2]
<strong>输出：</strong>[3,3,2]
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>root = [3,2,4,1]
<strong>输出：</strong>[7,9,4,10]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数介于 <code>0</code>&nbsp;和 <code>10<sup>4</sup></code><sup>&nbsp;</sup>之间。</li>
	<li>每个节点的值介于 <code>-10<sup>4</sup></code>&nbsp;和&nbsp;<code>10<sup>4</sup></code>&nbsp;之间。</li>
	<li>树中的所有值 <strong>互不相同</strong> 。</li>
	<li>给定的树为二叉搜索树。</li>
</ul>


## 题解

### cpp [🔗](convert-bst-to-greater-tree.cpp) 
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
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) return nullptr;
        root->val += addTree(root->right, 0);
        convertBST(root->left);
        convertBST(root->right);
        addLeft(root->left, root->val);
        return root;
    }

    void addLeft(TreeNode* root, int val) {
        if (root == nullptr) return;
        root->val += val;
        addLeft(root->left, val);
        addLeft(root->right, val);
    }

    int addTree(TreeNode *root, int rootVal) {
        if (root == nullptr) return 0;
        return addTree(root->left, 0) + addTree(root->right, 0) + root->val + rootVal;
    }


};
```


## 相关话题

- [树](../../tags/tree.md) 
- [深度优先搜索](../../tags/depth-first-search.md) 
- [二叉搜索树](../../tags/binary-search-tree.md) 
- [二叉树](../../tags/binary-tree.md) 


## 相似题目



## Links

- [Prev](../encode-and-decode-tinyurl/README.md) 
- [Next](../single-element-in-a-sorted-array/README.md) 

