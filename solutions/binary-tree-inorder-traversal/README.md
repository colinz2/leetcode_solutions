
# [二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal)

## 题目描述

<p>给定一个二叉树的根节点 <code>root</code> ，返回 <em>它的 <strong>中序</strong>&nbsp;遍历</em> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg" style="height: 200px; width: 125px;" />
<pre>
<strong>输入：</strong>root = [1,null,2,3]
<strong>输出：</strong>[1,3,2]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = []
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = [1]
<strong>输出：</strong>[1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[0, 100]</code> 内</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶:</strong>&nbsp;递归算法很简单，你可以通过迭代算法完成吗？</p>


## 题解

### python3 [🔗](binary-tree-inorder-traversal.py) 
```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        stack = []
        res = []
        while root or len(stack) > 0:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            res.append(root.val)
            root = root.right
        return res
```
### cpp [🔗](binary-tree-inorder-traversal.cpp) 
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            auto node = st.top(); st.pop();
            res.emplace_back(node->val);
            root = node->right;
        }
        return res;
    }
};
```
### golang [🔗](binary-tree-inorder-traversal.go) 
```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func inorderTraversal(root *TreeNode) []int {
	res := []int{}
	var inorder func(*TreeNode)

	inorder = func(n *TreeNode) {
		if n == nil {
			return
		}
		inorder(n.Left)
		res = append(res, n.Val)
		inorder(n.Right)
	}

	inorder(root)
	return res
}

```


## 相关话题

- [栈](https://leetcode-cn.com/tag/stack) 
- [树](https://leetcode-cn.com/tag/tree) 
- [深度优先搜索](https://leetcode-cn.com/tag/depth-first-search) 
- [二叉树](https://leetcode-cn.com/tag/binary-tree) 


## 相似题目

- [验证二叉搜索树](../validate-binary-search-tree/README.md)  [Medium] 
- [二叉树的前序遍历](../binary-tree-preorder-traversal/README.md)  [Easy] 
- [二叉树的后序遍历](../binary-tree-postorder-traversal/README.md)  [Easy] 
- [二叉搜索树迭代器](../binary-search-tree-iterator/README.md)  [Medium] 
- [二叉搜索树中第K小的元素](../kth-smallest-element-in-a-bst/README.md)  [Medium] 
- [将二叉搜索树转化为排序的双向链表](../convert-binary-search-tree-to-sorted-doubly-linked-list/README.md)  [Medium] 


## Links

- [Prev](../restore-ip-addresses/README.md) 
- [Next](../unique-binary-search-trees/README.md) 

