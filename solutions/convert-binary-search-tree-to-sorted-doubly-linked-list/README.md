
# [将二叉搜索树转化为排序的双向链表](https://leetcode-cn.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list)

## 题目描述

<p>将一个 <strong>二叉搜索树</strong> 就地转化为一个 <strong>已排序的双向循环链表</strong> 。</p>

<p>对于双向循环列表，你可以将左右孩子指针作为双向循环链表的前驱和后继指针，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。</p>

<p>特别地，我们希望可以 <strong>就地</strong> 完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中最小元素的指针。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>root = [4,2,5,1,3] 

<img src="https://assets.leetcode.com/uploads/2018/10/12/bstdllreturndll.png" style="width: 400px;" />
<strong>输出：</strong>[1,2,3,4,5]

<strong>解释：</strong>下图显示了转化后的二叉搜索树，实线表示后继关系，虚线表示前驱关系。
<img src="https://assets.leetcode.com/uploads/2018/10/12/bstdllreturnbst.png" style="width: 400px;" />
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [2,1,3]
<strong>输出：</strong>[1,2,3]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = []
<strong>输出：</strong>[]
<strong>解释：</strong>输入是空树，所以输出也是空链表。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>root = [1]
<strong>输出：</strong>[1]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-1000 <= Node.val <= 1000</code></li>
	<li><code>Node.left.val < Node.val < Node.right.val</code></li>
	<li><code>Node.val</code> 的所有值都是独一无二的</li>
	<li><code>0 <= Number of Nodes <= 2000</code></li>
</ul>


## 题解

### cpp [🔗](convert-binary-search-tree-to-sorted-doubly-linked-list.cpp) 
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return nullptr;
        std::stack<Node*> st;
        Node dummy;
        Node* prev = &dummy;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            auto node = st.top(); st.pop();
            prev->right = node;
            node->left = prev;
            prev = node;
            root = node->right;
        }
        dummy.right->left = prev;
        prev->right = dummy.right;
        return dummy.right;
    }
};
```


## 相关话题

- [栈](../../tags/stack.md) 
- [树](../../tags/tree.md) 
- [深度优先搜索](../../tags/depth-first-search.md) 
- [二叉搜索树](../../tags/binary-search-tree.md) 
- [链表](../../tags/linked-list.md) 
- [二叉树](../../tags/binary-tree.md) 
- [双向链表](../../tags/doubly-linked-list.md) 


## 相似题目

- [二叉树的中序遍历](../binary-tree-inorder-traversal/README.md)  [Easy] 


## Links

- [Prev](../find-smallest-letter-greater-than-target/README.md) 
- [Next](../n-ary-tree-level-order-traversal/README.md) 

