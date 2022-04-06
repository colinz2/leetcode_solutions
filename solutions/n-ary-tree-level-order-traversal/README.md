
# [N 叉树的层序遍历](https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal)

## 题目描述

<p>给定一个 N 叉树，返回其节点值的<em>层序遍历</em>。（即从左到右，逐层遍历）。</p>

<p>树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png" style="width: 100%; max-width: 300px;" /></p>

<pre>
<strong>输入：</strong>root = [1,null,3,2,4,null,5,6]
<strong>输出：</strong>[[1],[3,2,4],[5,6]]
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png" style="width: 296px; height: 241px;" /></p>

<pre>
<strong>输入：</strong>root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<strong>输出：</strong>[[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树的高度不会超过 <code>1000</code></li>
	<li>树的节点总数在 <code>[0, 10^4]</code> 之间</li>
</ul>


## 题解

### cpp [🔗](n-ary-tree-level-order-traversal.cpp) 
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
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> _q;
        auto pushq = [&](Node* node) {
            if (node) _q.push(node);
        };

        pushq(root);
        vector<vector<int>> res;
        vector<int> tmp;
        while (_q.size() > 0) {
            int n = _q.size();
            tmp.clear();
            for (int i = 0; i < n; i++) {
                Node* node = _q.front(); 
                tmp.push_back(node->val);
                for (auto& child : node->children) {
                    pushq(child);
                }
                _q.pop();
            }
            res.emplace_back(tmp);
        }
        return res;
    }
};
```


## 相关话题

- [树](https://leetcode-cn.com/tag/tree) 
- [广度优先搜索](https://leetcode-cn.com/tag/breadth-first-search) 


## 相似题目

- [二叉树的层序遍历](../binary-tree-level-order-traversal/README.md)  [Medium] 
- [N 叉树的前序遍历](../n-ary-tree-preorder-traversal/README.md)  [Easy] 


## Links

- [Prev](../convert-binary-search-tree-to-sorted-doubly-linked-list/README.md) 
- [Next](../flatten-a-multilevel-doubly-linked-list/README.md) 

