
# [](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii)

## 题目描述



## 题解

### cpp [🔗](populating-next-right-pointers-in-each-node-ii.cpp) 
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
```


## 相关话题



## 相似题目



## Links

- [Prev](../populating-next-right-pointers-in-each-node/README.md) 
- [Next](../pascals-triangle/README.md) 

