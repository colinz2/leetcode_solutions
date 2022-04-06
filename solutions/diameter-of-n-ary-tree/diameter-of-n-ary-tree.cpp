// @Title: Diameter of N-Ary Tree
// @Author: colinjxc
// @Date: 2022-03-01T21:15:26+08:00
// @URL: https://leetcode-cn.com/problems/diameter-of-n-ary-tree


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
    int diameter(Node* root) {
        int diameter = 0;
        height(root, &diameter);
        return diameter;
    }

    int height(Node* root, int *diameter) {
        if (root == nullptr) {
            return 0;
        }
        int max_height = 0, second_height = 0;
        for (auto &child : root->children) {
            int h = height(child, diameter);
            if (h > max_height) {
                second_height = max_height;
                max_height = h;
            } else if (h > second_height) {
                second_height = h;
            }
        }
        *diameter = std::max(*diameter, max_height + second_height);
        return max_height + 1;
    }
};
