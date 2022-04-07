
# [N 叉树的前序遍历](https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal)

## 题目描述

<p>给定一个 n&nbsp;叉树的根节点 <meta charset="UTF-8" />&nbsp;<code>root</code>&nbsp;，返回 <em>其节点值的<strong> 前序遍历</strong></em> 。</p>

<p>n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 <code>null</code> 分隔（请参见示例）。</p>

<p><br />
<strong>示例 1：</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png" style="height: 193px; width: 300px;" /></p>

<pre>
<strong>输入：</strong>root = [1,null,3,2,4,null,5,6]
<strong>输出：</strong>[1,3,5,6,2,4]
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png" style="height: 272px; width: 300px;" /></p>

<pre>
<strong>输入：</strong>root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<strong>输出：</strong>[1,2,3,6,7,11,14,4,8,12,5,9,13,10]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>节点总数在范围<meta charset="UTF-8" />&nbsp;<code>[0, 10<sup>4</sup>]</code>内</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
	<li>n 叉树的高度小于或等于 <code>1000</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>递归法很简单，你可以使用迭代法完成此题吗?</p>


## 题解

### cpp [🔗](n-ary-tree-preorder-traversal.cpp) 
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
    vector<int> preorder(Node* root) {
        std::stack<Node*> st;
        std::vector<int> res;
        auto _push_stack = [&](Node* node) {
            if (node) st.push(node);
        };
        _push_stack(root);
        while (st.size() > 0) {
            Node* node = st.top();
            res.push_back(node->val);
            st.pop();
            
            for (auto it = node->children.rbegin(); 
                    it != node->children.rend(); it++) {
                _push_stack(*it);
            }
        }

        return res;
    }
};
```


## 相关话题

- [栈](https://leetcode-cn.com/tag/stack) 
- [树](https://leetcode-cn.com/tag/tree) 
- [深度优先搜索](https://leetcode-cn.com/tag/depth-first-search) 


## 相似题目

- [二叉树的前序遍历](../binary-tree-preorder-traversal/README.md)  [Easy] 
- [N 叉树的层序遍历](../n-ary-tree-level-order-traversal/README.md)  [Medium] 


## Links

- [Prev](../maximum-depth-of-n-ary-tree/README.md) 
- [Next](../search-in-a-binary-search-tree/README.md) 

