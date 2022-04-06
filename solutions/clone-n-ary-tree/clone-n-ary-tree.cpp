// @Title: Clone N-ary Tree
// @Author: colinjxc
// @Date: 2022-03-01T21:40:37+08:00
// @URL: https://leetcode-cn.com/problems/clone-n-ary-tree


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
    Node* cloneTree(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        Node* newRoot = new Node(root->val);
        for (auto child : root->children) {
            newRoot->children.push_back(cloneTree(child));
        }

        return newRoot;
    }
};
