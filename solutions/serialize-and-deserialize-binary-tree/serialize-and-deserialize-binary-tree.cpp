// @Title: Serialize and Deserialize Binary Tree
// @Author: colinjxc
// @Date: 2022-02-07T21:31:47+08:00
// @URL: https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void serializeTree(TreeNode* root, ostringstream& out) {
        if (root == nullptr) {
            out << "null ";
            return;
        }
        out << std::to_string(root->val) << " ";
        serializeTree(root->left, out);
        serializeTree(root->right, out);
    };
    
    TreeNode* deserializeTree(istringstream& in) {
        string str;
        in >> str;
        if (str == "null") return nullptr;
        TreeNode* node = new TreeNode(stoi(str));
        node->left = deserializeTree(in);
        node->right = deserializeTree(in);
        return node;
    };

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out_stream;
        serializeTree(root, out_stream);
        return out_stream.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeTree(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
