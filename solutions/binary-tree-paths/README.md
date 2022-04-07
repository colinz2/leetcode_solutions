
# [二叉树的所有路径](https://leetcode-cn.com/problems/binary-tree-paths)

## 题目描述

<p>给你一个二叉树的根节点 <code>root</code> ，按 <strong>任意顺序</strong> ，返回所有从根节点到叶子节点的路径。</p>

<p><strong>叶子节点</strong> 是指没有子节点的节点。</p>
&nbsp;

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/12/paths-tree.jpg" style="width: 207px; height: 293px;" />
<pre>
<strong>输入：</strong>root = [1,2,3,null,5]
<strong>输出：</strong>["1-&gt;2-&gt;5","1-&gt;3"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [1]
<strong>输出：</strong>["1"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在范围 <code>[1, 100]</code> 内</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>


## 题解

### cpp [🔗](binary-tree-paths.cpp) 
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {


    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == NULL) return res;
        
        string v = to_string(root->val);
        
        if (root->left == NULL && root->right == NULL) {
            res.push_back(v);
            return res;
        }
        
        vector<string> lv = binaryTreePaths(root->left);
        vector<string> rv = binaryTreePaths(root->right);
        
        
        for (string s : lv) {
            res.push_back(v + "->" + s);
        }
        for (string s : rv) {
            res.push_back(v + "->" + s);
        }
        
        return res;
    }
};
```


## 相关话题

- [树](../../tags/tree.md) 
- [深度优先搜索](../../tags/depth-first-search.md) 
- [字符串](../../tags/string.md) 
- [回溯](../../tags/backtracking.md) 
- [二叉树](../../tags/binary-tree.md) 


## 相似题目



## Links

- [Prev](../factor-combinations/README.md) 
- [Next](../add-digits/README.md) 

