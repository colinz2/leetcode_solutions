
# [N 叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree)

## 题目描述

<p>给定一个 N 叉树，找到其最大深度。</p>

<p class="MachineTrans-lang-zh-CN">最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。</p>

<p class="MachineTrans-lang-zh-CN">N 叉树输入按层序遍历序列化表示，每组子节点由空值分隔（请参见示例）。</p>

<p class="MachineTrans-lang-zh-CN"> </p>

<p><strong>示例 1：</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png" style="width: 100%; max-width: 300px;" /></p>

<pre>
<strong>输入：</strong>root = [1,null,3,2,4,null,5,6]
<strong>输出：</strong>3
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png" style="width: 296px; height: 241px;" /></p>

<pre>
<strong>输入：</strong>root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<strong>输出：</strong>5
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树的深度不会超过 <code>1000</code> 。</li>
	<li>树的节点数目位于 <code>[0, 10<sup>4</sup>]</code> 之间。</li>
</ul>


## 题解

### cpp [🔗](maximum-depth-of-n-ary-tree.cpp) 
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        int max = 0;
        for (auto &node : root->children) {
            int node_depth = maxDepth(node);
            if (node_depth > max) {
                max = node_depth;
            }
        }
        return max + 1;
    }
};
```
### golang [🔗](maximum-depth-of-n-ary-tree.go) 
```golang
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func maxDepth(root *Node) int {
    q := []*Node{}
    if root == nil {
        return 0
    }
    depth := 0
    q = append(q, root)

    for {
        levelCnt := len(q)
        if levelCnt == 0 {
            break
        }

        for i := 0; i < levelCnt; i++ {
            for _, childNode := range q[i].Children {
                if childNode != nil {
                    q = append(q, childNode)
                }
            }
        }

        q = q[levelCnt:len(q)]
        depth++
    }
    return depth
}
```


## 相关话题

- [树](../../tags/tree.md) 
- [深度优先搜索](../../tags/depth-first-search.md) 
- [广度优先搜索](../../tags/breadth-first-search.md) 


## 相似题目

- [二叉树的最大深度](../maximum-depth-of-binary-tree/README.md)  [Easy] 


## Links

- [Prev](../flatten-a-multilevel-doubly-linked-list/README.md) 
- [Next](../n-ary-tree-preorder-traversal/README.md) 

