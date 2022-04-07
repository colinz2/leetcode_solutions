
# [对称二叉树](https://leetcode-cn.com/problems/symmetric-tree)

## 题目描述

<p>给你一个二叉树的根节点 <code>root</code> ， 检查它是否轴对称。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/symtree1.jpg" style="width: 354px; height: 291px;" />
<pre>
<strong>输入：</strong>root = [1,2,2,3,4,4,3]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/symtree2.jpg" style="width: 308px; height: 258px;" />
<pre>
<strong>输入：</strong>root = [1,2,2,null,3,null,3]
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[1, 1000]</code> 内</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你可以运用递归和迭代两种方法解决这个问题吗？</p>


## 题解

### golang [🔗](symmetric-tree.go) 
```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSymmetric(root *TreeNode) bool {
    if root == nil {
        return true
    }
    return isSym(root.Left, root.Right)
}

func isSym(left, right *TreeNode) bool {
    if left == nil && right ==  nil {
        return true
    } 

    if left == nil || right == nil  {
        return false
    }

    if left.Val != right.Val {
        return false
    } else {
        return isSym(left.Left, right.Right) && isSym(left.Right, right.Left)
    }
}
```
### cpp [🔗](symmetric-tree.cpp) 
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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return  issym(root->left, root->right);
    }
    
private:
    bool issym(TreeNode* l, TreeNode* r) {
        if (l == NULL && r == NULL) {
            return true;
        }
        
        if (l == NULL || r == NULL) {
            return false;
        }
        
        if (l->val == r->val) {
            return issym(l->left, r->right) && issym(l->right, r->left);
        } else {
            return false;
        }

    }
};
```


## 相关话题

- [树](../../tags/tree.md) 
- [深度优先搜索](../../tags/depth-first-search.md) 
- [广度优先搜索](../../tags/breadth-first-search.md) 
- [二叉树](../../tags/binary-tree.md) 


## 相似题目



## Links

- [Prev](../same-tree/README.md) 
- [Next](../binary-tree-level-order-traversal/README.md) 

