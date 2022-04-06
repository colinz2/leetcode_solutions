
# [两数之和 IV - 输入 BST](https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst)

## 题目描述

<p>给定一个二叉搜索树 <code>root</code> 和一个目标结果 <code>k</code>，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 <code>true</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/21/sum_tree_1.jpg" style="height: 229px; width: 400px;" />
<pre>
<strong>输入:</strong> root = [5,3,6,2,4,null,7], k = 9
<strong>输出:</strong> true
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/21/sum_tree_2.jpg" style="height: 229px; width: 400px;" />
<pre>
<strong>输入:</strong> root = [5,3,6,2,4,null,7], k = 28
<strong>输出:</strong> false
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li>二叉树的节点个数的范围是&nbsp;&nbsp;<code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>4</sup>&nbsp;&lt;= Node.val &lt;= 10<sup>4</sup></code></li>
	<li><code>root</code>&nbsp;为二叉搜索树</li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>


## 题解

### cpp [🔗](two-sum-iv-input-is-a-bst.cpp) 
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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return preorderFind(root, k, seen);
    }
    
    bool preorderFind(TreeNode* root, int k, unordered_set<int>& seen) {
        if (root == NULL) {
            return false;
        }
        if (seen.find(k - root->val) != seen.end()) {
            return true;
        }
        seen.insert(root->val);
        return preorderFind(root->left, k, seen) || preorderFind(root->right, k, seen);
    }
};
```


## 相关话题

- [树](https://leetcode-cn.com/tag/tree) 
- [深度优先搜索](https://leetcode-cn.com/tag/depth-first-search) 
- [广度优先搜索](https://leetcode-cn.com/tag/breadth-first-search) 
- [二叉搜索树](https://leetcode-cn.com/tag/binary-search-tree) 
- [哈希表](https://leetcode-cn.com/tag/hash-table) 
- [双指针](https://leetcode-cn.com/tag/two-pointers) 
- [二叉树](https://leetcode-cn.com/tag/binary-tree) 


## 相似题目

- [两数之和](../two-sum/README.md)  [Easy] 
- [两数之和 II - 输入有序数组](../two-sum-ii-input-array-is-sorted/README.md)  [Medium] 


## Links

- [Prev](../average-of-levels-in-binary-tree/README.md) 
- [Next](../image-smoother/README.md) 

