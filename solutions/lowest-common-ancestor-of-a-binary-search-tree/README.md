
# [二叉搜索树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree)

## 题目描述

<p>给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。</p>

<p><a href="https://baike.baidu.com/item/%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88/8918834?fr=aladdin" target="_blank">百度百科</a>中最近公共祖先的定义为：&ldquo;对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（<strong>一个节点也可以是它自己的祖先</strong>）。&rdquo;</p>

<p>例如，给定如下二叉搜索树:&nbsp; root =&nbsp;[6,2,8,0,4,7,9,null,null,3,5]</p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/binarysearchtree_improved.png" style="height: 190px; width: 200px;"></p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
<strong>输出:</strong> 6 
<strong>解释: </strong>节点 <code>2 </code>和节点 <code>8 </code>的最近公共祖先是 <code>6。</code>
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
<strong>输出:</strong> 2
<strong>解释: </strong>节点 <code>2</code> 和节点 <code>4</code> 的最近公共祖先是 <code>2</code>, 因为根据定义最近公共祖先节点可以为节点本身。</pre>

<p>&nbsp;</p>

<p><strong>说明:</strong></p>

<ul>
	<li>所有节点的值都是唯一的。</li>
	<li>p、q 为不同节点且均存在于给定的二叉搜索树中。</li>
</ul>


## 题解

### c [🔗](lowest-common-ancestor-of-a-binary-search-tree.c) 
```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL) {
        return NULL;
    }
    if (root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    } else if (root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;    
}
```
### cpp [🔗](lowest-common-ancestor-of-a-binary-search-tree.cpp) 
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (root->val > std::max(p->val, q->val)) {
                root = root->left;
            } else if (root->val < std::min(p->val, q->val)) {
                root = root->right;
            } else {
                return root;
            }
        }
        return root;
    }
};
```
### golang [🔗](lowest-common-ancestor-of-a-binary-search-tree.go) 
```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val   int
 *     Left  *TreeNode
 *     Right *TreeNode
 * }
 */

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
    if root != nil {
        if root.Val > p.Val && root.Val > q.Val {
            return lowestCommonAncestor(root.Left, p, q)
        } else if root.Val < p.Val && root.Val < q.Val {
            return lowestCommonAncestor(root.Right, p, q)
        }
    }
    return root
}
```
### python3 [🔗](lowest-common-ancestor-of-a-binary-search-tree.py) 
```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        while root != None:
            if root.val > max(p.val, q.val):
                root = root.left
            elif root.val < min(p.val, q.val):
                root = root.right
            else: 
                return root
        return root
```
### typescript [🔗](lowest-common-ancestor-of-a-binary-search-tree.typescript) 
```typescript
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function lowestCommonAncestor(root: TreeNode | null, p: TreeNode | null, q: TreeNode | null): TreeNode | null {
	if (root != null) {
        if (root.val > p.val && root.val > q.val) {
            return lowestCommonAncestor(root.left, p, q)
        } else if (root.val < p.val && root.val < q.val) {
            return lowestCommonAncestor(root.right, p, q)
        }
    }
    return root
};
```


## 相关话题

- [树](https://leetcode-cn.com/tag/tree) 
- [深度优先搜索](https://leetcode-cn.com/tag/depth-first-search) 
- [二叉搜索树](https://leetcode-cn.com/tag/binary-search-tree) 
- [二叉树](https://leetcode-cn.com/tag/binary-tree) 


## 相似题目

- [二叉树的最近公共祖先](../lowest-common-ancestor-of-a-binary-tree/README.md)  [Medium] 


## Links

- [Prev](../palindrome-linked-list/README.md) 
- [Next](../lowest-common-ancestor-of-a-binary-tree/README.md) 

