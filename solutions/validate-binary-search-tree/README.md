
# [验证二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree)

## 题目描述

<p>给你一个二叉树的根节点 <code>root</code> ，判断其是否是一个有效的二叉搜索树。</p>

<p><strong>有效</strong> 二叉搜索树定义如下：</p>

<ul>
	<li>节点的左子树只包含<strong> 小于 </strong>当前节点的数。</li>
	<li>节点的右子树只包含 <strong>大于</strong> 当前节点的数。</li>
	<li>所有左子树和右子树自身必须也是二叉搜索树。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg" style="width: 302px; height: 182px;" />
<pre>
<strong>输入：</strong>root = [2,1,3]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg" style="width: 422px; height: 292px;" />
<pre>
<strong>输入：</strong>root = [5,1,4,null,null,3,6]
<strong>输出：</strong>false
<strong>解释：</strong>根节点的值是 5 ，但是右子节点的值是 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目范围在<code>[1, 10<sup>4</sup>]</code> 内</li>
	<li><code>-2<sup>31</sup> &lt;= Node.val &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


## 题解

### cpp [🔗](validate-binary-search-tree.cpp) 
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
    //中序遍历，从小到大排列
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorderVisit(root, v);
        for (int i = 1; i < v.size(); i++) {
            if (v[i - 1] >= v[i]) {
                return false;
            }
        }
        return true;
    }

    void inorderVisit(TreeNode* root, vector<int>& v) {
        if (root) {
            inorderVisit(root->left, v);
            v.push_back(root->val);
            inorderVisit(root->right, v);
        }
    }
};
```


## 相关话题

- [树](https://leetcode-cn.com/tag/tree) 
- [深度优先搜索](https://leetcode-cn.com/tag/depth-first-search) 
- [二叉搜索树](https://leetcode-cn.com/tag/binary-search-tree) 
- [二叉树](https://leetcode-cn.com/tag/binary-tree) 


## 相似题目

- [二叉树的中序遍历](../binary-tree-inorder-traversal/README.md)  [Easy] 


## Links

- [Prev](../unique-binary-search-trees/README.md) 
- [Next](../recover-binary-search-tree/README.md) 

