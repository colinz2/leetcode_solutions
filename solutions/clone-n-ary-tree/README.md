
# [](https://leetcode-cn.com/problems/clone-n-ary-tree)

## 题目描述



## 题解

### cpp [🔗](clone-n-ary-tree.cpp) 
```cpp
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
```
### golang [🔗](clone-n-ary-tree.go) 
```golang
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func cloneTree(root *Node) *Node {
	if root == nil {
        return nil
    }
    newRoot := new(Node)
    newRoot.Val = root.Val
    for _, ch := range root.Children {
        newRoot.Children = append(newRoot.Children, cloneTree(ch))
    }

    return newRoot
}
```


## 相关话题



## 相似题目



## Links

- [Prev](../build-an-array-with-stack-operations/README.md) 
- [Next](../diameter-of-n-ary-tree/README.md) 

