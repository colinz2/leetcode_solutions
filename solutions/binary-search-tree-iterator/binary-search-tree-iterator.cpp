// @Title: Binary Search Tree Iterator
// @Author: colinjxc
// @Date: 2022-01-28T20:30:22+08:00
// @URL: https://leetcode-cn.com/problems/binary-search-tree-iterator


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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) : vec_(0), index_(0) {
        std::function<void(TreeNode*)> inorder = [&,this](TreeNode *node) {
            if (node == nullptr) return;
            inorder(node->left);
            vec_.push_back(node->val);
            inorder(node->right);
        };
        inorder(root);
    }
    
    int next() {
        return vec_[index_++];
    }
    
    bool hasNext() {
        if (index_ == vec_.size()) {
            return false;
        }
        return true;
    }
private:
    vector<int> vec_;
    int index_;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
