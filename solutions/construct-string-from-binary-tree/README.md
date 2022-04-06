
# [根据二叉树创建字符串](https://leetcode-cn.com/problems/construct-string-from-binary-tree)

## 题目描述

<p>你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。</p>

<p>空节点则用一对空括号 &quot;()&quot; 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 二叉树: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     

<strong>输出:</strong> &quot;1(2(4))(3)&quot;

<strong>解释:</strong> 原本将是&ldquo;1(2(4)())(3())&rdquo;，
在你省略所有不必要的空括号对之后，
它将是&ldquo;1(2(4))(3)&rdquo;。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> 二叉树: [1,2,3,null,4]
       1
     /   \
    2     3
     \  
      4 

<strong>输出:</strong> &quot;1(2()(4))(3)&quot;

<strong>解释:</strong> 和第一个示例相似，
除了我们不能省略第一个对括号来中断输入和输出之间的一对一映射关系。
</pre>


## 题解

### cpp [🔗](construct-string-from-binary-tree.cpp) 
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
    string tree2str(TreeNode* root) {
        string res;
        std::function<void(TreeNode*)> preorder = [&](TreeNode* node) {
            if (node == nullptr) return;
            res += std::to_string(node->val);
            if (node->left != nullptr || node->right != nullptr) {
                res += "(";
                preorder(node->left);
                res += ")";
            }
            if (node->right != nullptr ) {
                res += "(";
                preorder(node->right);
                res += ")";
            }
        };

        preorder(root);
        return res;
    }
};
```


## 相关话题

- [树](https://leetcode-cn.com/tag/tree) 
- [深度优先搜索](https://leetcode-cn.com/tag/depth-first-search) 
- [字符串](https://leetcode-cn.com/tag/string) 
- [二叉树](https://leetcode-cn.com/tag/binary-tree) 


## 相似题目



## Links

- [Prev](../design-compressed-string-iterator/README.md) 
- [Next](../merge-two-binary-trees/README.md) 

