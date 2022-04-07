
# [最接近的二叉搜索树值](https://leetcode-cn.com/problems/closest-binary-search-tree-value)

## 题目描述

<p>给定一个不为空的二叉搜索树和一个目标值 target，请在该二叉搜索树中找到最接近目标值 target 的数值。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>给定的目标值 target 是一个浮点数</li>
	<li>题目保证在该二叉搜索树中只会存在一个最接近目标值的数</li>
</ul>

<p><strong>示例：</strong></p>

<pre><strong>输入:</strong> root = [4,2,5,1,3]，目标值 target = 3.714286

    4
   / \
  2   5
 / \
1   3

<strong>输出:</strong> 4
</pre>


## 题解

### cpp [🔗](closest-binary-search-tree-value.cpp) 
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
    int closestValue(TreeNode* root, double target) {
        int closest = INT_MAX;
        auto getClose = [](int a, int b, double target) ->int {
            double d1 = static_cast<double>(a) - target;
            double d2 = static_cast<double>(b) - target;
            if (std::abs(d1) > std::abs(d2)) {
                return b;
            }
            return a;
        };

        std::function<void(TreeNode*)> search = [&](TreeNode* node) {
            if (node == nullptr) return;
            closest = getClose(closest, node->val, target);
            if (node->left == nullptr) {
                return search(node->right);
            } else if (node->right == nullptr) {
                return search(node->left);
            }
            search(node->left);
            search(node->right);
        };
        search(root);
        return closest;
    }
};
```


## 相关话题

- [树](../../tags/tree.md) 
- [深度优先搜索](../../tags/depth-first-search.md) 
- [二叉搜索树](../../tags/binary-search-tree.md) 
- [二分查找](../../tags/binary-search.md) 
- [二叉树](../../tags/binary-tree.md) 


## 相似题目

- [二叉搜索树中的搜索](../search-in-a-binary-search-tree/README.md)  [Easy] 


## Links

- [Prev](../missing-number/README.md) 
- [Next](../first-bad-version/README.md) 

