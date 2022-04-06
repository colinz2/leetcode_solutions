// @Title: Populating Next Right Pointers in Each Node II
// @Author: colinjxc
// @Date: 2022-02-05T00:26:15+08:00
// @URL: https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                Node* n = q.front();
                q.pop();
                if (i < len - 1) {
                    n->next = q.front();
                }
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
        }
        return root;
    }
};
