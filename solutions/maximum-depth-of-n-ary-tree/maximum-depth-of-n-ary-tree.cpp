// @Title: Maximum Depth of N-ary Tree
// @Author: realzhangm
// @Date: 2021-11-02T15:33:25+08:00
// @URL: https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree


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
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        int max = 0;
        for (auto &node : root->children) {
            int node_depth = maxDepth(node);
            if (node_depth > max) {
                max = node_depth;
            }
        }
        return max + 1;
    }
};
