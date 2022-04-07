
# [二叉搜索树中的搜索](https://leetcode-cn.com/problems/search-in-a-binary-search-tree)

## 题目描述

<p>给定二叉搜索树（BST）的根节点<meta charset="UTF-8" />&nbsp;<code>root</code>&nbsp;和一个整数值<meta charset="UTF-8" />&nbsp;<code>val</code>。</p>

<p>你需要在 BST 中找到节点值等于&nbsp;<code>val</code>&nbsp;的节点。 返回以该节点为根的子树。 如果节点不存在，则返回<meta charset="UTF-8" />&nbsp;<code>null</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/01/12/tree1.jpg" style="height: 179px; width: 250px;" /><meta charset="UTF-8" /></p>

<pre>
<b>输入：</b>root = [4,2,7,1,3], val = 2
<b>输出：</b>[2,1,3]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/12/tree2.jpg" style="height: 179px; width: 250px;" />
<pre>
<b>输入：</b>root = [4,2,7,1,3], val = 5
<b>输出：</b>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>数中节点数在&nbsp;<code>[1, 5000]</code>&nbsp;范围内</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>7</sup></code></li>
	<li><code>root</code>&nbsp;是二叉搜索树</li>
	<li><code>1 &lt;= val &lt;= 10<sup>7</sup></code></li>
</ul>


## 题解

### cpp [🔗](search-in-a-binary-search-tree.cpp) 
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
    TreeNode* searchBST(TreeNode* root, int val) {
        queue<TreeNode*> _q;
        _q.push(root);

        TreeNode* node = nullptr;
        while (!_q.empty()) {
            node = _q.front();
            _q.pop();
            if (node == nullptr || node->val == val) {
                return node;
            } else if (node->val < val) {
                _q.push(node->right);
            } else {
                _q.push(node->left);
            }
        }

        return nullptr;
    }
};
```
### golang [🔗](search-in-a-binary-search-tree.go) 
```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func searchBST(root *TreeNode, val int) *TreeNode {
	queue := list.New()
	node := queue.PushBack(root).Value.(*TreeNode)

	for queue.Len() != 0 {
		node = queue.Remove(queue.Front()).(*TreeNode)
		if node == nil || node.Val == val {
			break
		} else if val > node.Val {
			queue.PushBack(node.Right)
		} else {
			queue.PushBack(node.Left)
		}
	}
	return node
}
```


## 相关话题

- [树](../../tags/tree.md) 
- [二叉搜索树](../../tags/binary-search-tree.md) 
- [二叉树](../../tags/binary-tree.md) 


## 相似题目

- [最接近的二叉搜索树值](../closest-binary-search-tree-value/README.md)  [Easy] 


## Links

- [Prev](../n-ary-tree-preorder-traversal/README.md) 
- [Next](../search-in-a-sorted-array-of-unknown-size/README.md) 

