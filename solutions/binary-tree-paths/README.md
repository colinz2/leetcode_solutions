
# [](https://leetcode-cn.com/problems/binary-tree-paths)

## 题目描述



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



## 相似题目



## Links

- [Prev](../factor-combinations/README.md) 
- [Next](../add-digits/README.md) 

