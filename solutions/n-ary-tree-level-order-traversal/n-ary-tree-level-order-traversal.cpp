// @Title: N-ary Tree Level Order Traversal
// @Author: colinjxc
// @Date: 2022-01-26T13:08:25+08:00
// @URL: https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal


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
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> _q;
        auto pushq = [&](Node* node) {
            if (node) _q.push(node);
        };

        pushq(root);
        vector<vector<int>> res;
        vector<int> tmp;
        while (_q.size() > 0) {
            int n = _q.size();
            tmp.clear();
            for (int i = 0; i < n; i++) {
                Node* node = _q.front(); 
                tmp.push_back(node->val);
                for (auto& child : node->children) {
                    pushq(child);
                }
                _q.pop();
            }
            res.emplace_back(tmp);
        }
        return res;
    }
};
