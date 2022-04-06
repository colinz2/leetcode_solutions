// @Title: N-ary Tree Preorder Traversal
// @Author: colinjxc
// @Date: 2022-01-25T22:54:41+08:00
// @URL: https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal


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
    vector<int> preorder(Node* root) {
        std::stack<Node*> st;
        std::vector<int> res;
        auto _push_stack = [&](Node* node) {
            if (node) st.push(node);
        };
        _push_stack(root);
        while (st.size() > 0) {
            Node* node = st.top();
            res.push_back(node->val);
            st.pop();
            
            for (auto it = node->children.rbegin(); 
                    it != node->children.rend(); it++) {
                _push_stack(*it);
            }
        }

        return res;
    }
};
