
# [二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal)

## 题目描述

<p>给你二叉树的根节点 <code>root</code> ，返回其节点值的 <strong>层序遍历</strong> 。 （即逐层地，从左到右访问所有节点）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg" style="width: 277px; height: 302px;" />
<pre>
<strong>输入：</strong>root = [3,9,20,null,null,15,7]
<strong>输出：</strong>[[3],[9,20],[15,7]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [1]
<strong>输出：</strong>[[1]]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = []
<strong>输出：</strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[0, 2000]</code> 内</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
</ul>


## 题解

### golang [🔗](binary-tree-level-order-traversal.go) 
```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
    res := make([][]int, 0)
    q := make([]*TreeNode, 0)

    q = append(q, root)
    for len(q) > 0 {
        tmp := []int{}
        size := len(q)
        for i := 0; i < size; i++ {
            node := q[i]
            if node != nil {
                tmp = append(tmp, node.Val)
                q = append(q, node.Left, node.Right)
            }
        }
        q = q[size:]
        if len(tmp) > 0 {
            res = append(res, tmp)
        }
    }
    return res;
}
```
### cpp [🔗](binary-tree-level-order-traversal.cpp) 
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> _q;
        _q.push(root);

        vector<int> tmp;
        while (!_q.empty()) {
            int n = _q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = _q.front();
                _q.pop();
                if (node == nullptr) continue;
                tmp.push_back(node->val);
                _q.push(node->left);
                _q.push(node->right);
            }
            if (tmp.size() > 0) {
                res.push_back(tmp);
                tmp.clear();
            }
        }
        return res;
    }
};
```


## 相关话题

- [树](https://leetcode-cn.com/tag/tree) 
- [广度优先搜索](https://leetcode-cn.com/tag/breadth-first-search) 
- [二叉树](https://leetcode-cn.com/tag/binary-tree) 


## 相似题目

- [二叉树的锯齿形层序遍历](../binary-tree-zigzag-level-order-traversal/README.md)  [Medium] 
- [二叉树的层序遍历 II](../binary-tree-level-order-traversal-ii/README.md)  [Medium] 
- [二叉树的最小深度](../minimum-depth-of-binary-tree/README.md)  [Easy] 
- [二叉树的层平均值](../average-of-levels-in-binary-tree/README.md)  [Easy] 
- [N 叉树的层序遍历](../n-ary-tree-level-order-traversal/README.md)  [Medium] 


## Links

- [Prev](../symmetric-tree/README.md) 
- [Next](../binary-tree-zigzag-level-order-traversal/README.md) 

