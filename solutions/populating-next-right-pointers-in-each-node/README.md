
# [](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node)

## 题目描述



## 题解

### c [🔗](populating-next-right-pointers-in-each-node.c) 
```c
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
    if (root == NULL) return NULL;
    // 只有非叶子节点才可以这样做。
    if (root->left) {
        root->left->next = root->right;
        if (root->next) {
            root->right->next = root->next->left;
        }
    }
    connect(root->left);
    connect(root->right);
    return root;
}
```
### cpp [🔗](populating-next-right-pointers-in-each-node.cpp) 
```cpp
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
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node* node = q.front();
                q.pop();
                if (i < n - 1) {
                    node->next = q.front();
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return root;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../flatten-binary-tree-to-linked-list/README.md) 
- [Next](../populating-next-right-pointers-in-each-node-ii/README.md) 

