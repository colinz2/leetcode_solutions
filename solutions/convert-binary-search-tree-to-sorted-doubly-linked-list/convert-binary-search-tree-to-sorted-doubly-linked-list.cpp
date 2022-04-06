// @Title: Convert Binary Search Tree to Sorted Doubly Linked List
// @Author: colinjxc
// @Date: 2022-02-04T13:28:30+08:00
// @URL: https://leetcode-cn.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list


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
