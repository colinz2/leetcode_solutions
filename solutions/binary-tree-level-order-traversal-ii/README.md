
# [二叉树的层序遍历 II](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii)

## 题目描述

<p>给定一个二叉树，返回其节点值自底向上的层序遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）</p>

<p>例如：<br />
给定二叉树 <code>[3,9,20,null,null,15,7]</code>,</p>

<pre>
    3
   / \
  9  20
    /  \
   15   7
</pre>

<p>返回其自底向上的层序遍历为：</p>

<pre>
[
  [15,7],
  [9,20],
  [3]
]
</pre>


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
- [Next](../balanced-binary-tree/README.md) 

