
# [二叉搜索树中第K小的元素](https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst)

## 题目描述

<p>给定一个二叉搜索树的根节点 <code>root</code> ，和一个整数 <code>k</code> ，请你设计一个算法查找其中第 <code>k</code><strong> </strong>个最小元素（从 1 开始计数）。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/28/kthtree1.jpg" style="width: 212px; height: 301px;" />
<pre>
<strong>输入：</strong>root = [3,1,4,null,2], k = 1
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/28/kthtree2.jpg" style="width: 382px; height: 302px;" />
<pre>
<strong>输入：</strong>root = [5,3,6,2,4,null,null,1], k = 3
<strong>输出：</strong>3
</pre>

<p> </p>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数为 <code>n</code> 。</li>
	<li><code>1 <= k <= n <= 10<sup>4</sup></code></li>
	<li><code>0 <= Node.val <= 10<sup>4</sup></code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong>如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 <code>k</code> 小的值，你将如何优化算法？</p>


## 题解

### cpp [🔗](kth-smallest-element-in-a-bst.cpp) 
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
    int kthSmallest(TreeNode* root, int k) {
        std::vector<TreeNode*> stack;
        while (root || !stack.empty()) {
            while (root) {
                stack.push_back(root);
                root = root->left;
            }
            root = stack.back();
            stack.pop_back();
            if (--k == 0) {
                return root->val;
            }
            root = root->right;
        }
        return -1;
    }
};
```
### golang [🔗](kth-smallest-element-in-a-bst.go) 
```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func kthSmallest(root *TreeNode, k int) int {
    stack := make([]*TreeNode, 0)
    for root != nil || len(stack) > 0 {
        for root != nil {
            stack = append(stack, root)
            root = root.Left
        }
        root = stack[len(stack)-1]
        stack = stack[0:len(stack)-1]
        k--
        if k == 0 {
            return root.Val
        }
        root = root.Right
    }
    return 0
}
```
### python [🔗](kth-smallest-element-in-a-bst.py) 
```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        stack = []
        while root is not None or len(stack) > 0:
            while root is not None:
                stack.append(root)
                root = root.left
            root = stack.pop()
            k -= 1
            if k == 0:
                return root.val
            root = root.right
        return -1
```
### python3 [🔗](kth-smallest-element-in-a-bst.py) 
```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.cnt = 0
        self.val = 0

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        def inorder(node: Optional[TreeNode]):
            if node == None or self.cnt > k:
                return
            inorder(node.left)
            self.cnt += 1
            if self.cnt == k:
                self.val = node.val
            inorder(node.right)

        inorder(root)
        return self.val
```
### c [🔗](kth-smallest-element-in-a-bst.c) 
```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int kthSmallest(struct TreeNode* root, int k){
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10000);
    size_t stack_index = 0;
    int val = 0;

    struct TreeNode* node = root;
    while (node != NULL || stack_index != 0) {
        while (node != NULL) {
            stack[stack_index++] = node;
            node = node->left;
        }
        // 是 --stack_index 不是 stack_index--
        node = stack[--stack_index];
        if (--k == 0) {
            val = node->val;
            break;
        }
        node = node->right;
    }

    free(stack);
    return val;
}
```


## 相关话题

- [树](../../tags/tree.md) 
- [深度优先搜索](../../tags/depth-first-search.md) 
- [二叉搜索树](../../tags/binary-search-tree.md) 
- [二叉树](../../tags/binary-tree.md) 


## 相似题目

- [二叉树的中序遍历](../binary-tree-inorder-traversal/README.md)  [Easy] 
- [二叉树中第二小的节点](../second-minimum-node-in-a-binary-tree/README.md)  [Easy] 


## Links

- [Prev](../summary-ranges/README.md) 
- [Next](../power-of-two/README.md) 

