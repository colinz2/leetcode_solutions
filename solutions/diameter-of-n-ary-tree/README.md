
# [N 叉树的直径](https://leetcode-cn.com/problems/diameter-of-n-ary-tree)

## 题目描述

<p>给定一棵 N 叉树的根节点&nbsp;<code>root</code>&nbsp;，计算这棵树的直径长度。</p>

<p>N 叉树的直径指的是树中任意两个节点间路径中<strong> 最长 </strong>路径的长度。这条路径可能经过根节点，也可能不经过根节点。</p>

<p><em>（N 叉树的输入序列以层序遍历的形式给出，每组子节点用 null 分隔）</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/07/19/sample_2_1897.png" style="height:173px; width:324px" /></p>

<pre>
<strong>输入：</strong>root = [1,null,3,2,4,null,5,6]
<strong>输出：</strong>3
<strong>解释：</strong>直径如图中红线所示。</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/07/19/sample_1_1897.png" style="height:246px; width:253px" /></strong></p>

<pre>
<strong>输入：</strong>root = [1,null,2,null,3,4,null,5,null,6]
<strong>输出：</strong>4
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/07/19/sample_3_1897.png" style="height:326px; width:369px" /></p>

<pre>
<strong>输入:</strong> root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<strong>输出:</strong> 7
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>N 叉树的深度小于或等于&nbsp;<code>1000</code>&nbsp;。</li>
	<li>节点的总个数在&nbsp;<code>[0,&nbsp;10^4]</code>&nbsp;间。</li>
</ul>


## 题解

### cpp [🔗](diameter-of-n-ary-tree.cpp) 
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
    int diameter(Node* root) {
        int diameter = 0;
        height(root, &diameter);
        return diameter;
    }

    int height(Node* root, int *diameter) {
        if (root == nullptr) {
            return 0;
        }
        int max_height = 0, second_height = 0;
        for (auto &child : root->children) {
            int h = height(child, diameter);
            if (h > max_height) {
                second_height = max_height;
                max_height = h;
            } else if (h > second_height) {
                second_height = h;
            }
        }
        *diameter = std::max(*diameter, max_height + second_height);
        return max_height + 1;
    }
};
```


## 相关话题

- [树](../../tags/tree.md) 
- [深度优先搜索](../../tags/depth-first-search.md) 


## 相似题目



## Links

- [Prev](../clone-n-ary-tree/README.md) 
- [Next](../merge-in-between-linked-lists/README.md) 

