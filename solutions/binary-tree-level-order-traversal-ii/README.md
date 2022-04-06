
# [二叉树的层序遍历 II](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii)

## 题目描述

<p>给你二叉树的根节点 <code>root</code> ，返回其节点值 <strong>自底向上的层序遍历</strong> 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg" style="width: 277px; height: 302px;" />
<pre>
<strong>输入：</strong>root = [3,9,20,null,null,15,7]
<strong>输出：</strong>[[15,7],[9,20],[3]]
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

### golang [🔗](binary-tree-level-order-traversal-ii.go) 
```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrderBottom(root *TreeNode) [][]int {
    res := [][]int{}
    if root == nil {
        return res
    }
    q := []*TreeNode{}
    q = append(q, root)
    for {
        levelLen := len(q)
        if levelLen == 0 {
            break;
        }
        levelVec := make([]int, 0, levelLen)
        for i := 0; i < levelLen; i++ {
            levelVec = append(levelVec, q[i].Val)
            if q[i].Left != nil {
                q = append(q, q[i].Left)
            }

            if q[i].Right != nil {
                q = append(q, q[i].Right)
            }
        }
        res = append(res, levelVec)
        q = q[levelLen: len(q)]
    }
    reverse(res)
    return res;
}

func reverse(vec [][]int) {
    l, r := 0, len(vec)
    if r == 0 {
        return 
    } else {
        r--
    }

    for (l < r) {
        vec[l], vec[r] = vec[r], vec[l]
        l++
        r--
    }
}


```


## 相关话题

- [树](https://leetcode-cn.com/tag/tree) 
- [广度优先搜索](https://leetcode-cn.com/tag/breadth-first-search) 
- [二叉树](https://leetcode-cn.com/tag/binary-tree) 


## 相似题目

- [二叉树的层序遍历](../binary-tree-level-order-traversal/README.md)  [Medium] 
- [二叉树的层平均值](../average-of-levels-in-binary-tree/README.md)  [Easy] 


## Links

- [Prev](../maximum-depth-of-binary-tree/README.md) 
- [Next](../convert-sorted-array-to-binary-search-tree/README.md) 

