
# [](https://leetcode-cn.com/problems/binary-search-tree-iterator)

## 题目描述



## 题解

### c [🔗](binary-search-tree-iterator.c) 
```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



typedef struct {
    struct TreeNode* head;
} BSTIterator;

void inorder(BSTIterator* bst_iter, struct TreeNode* root) {
    if (root == NULL) return;
    inorder(bst_iter, root->right);
    root->right = bst_iter->head->right;
    bst_iter->head->right = root;
    inorder(bst_iter, root->left);
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* bst_iter = malloc(sizeof(BSTIterator));
    bst_iter->head = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    bst_iter->head->left = NULL;
    bst_iter->head->right = NULL;

    inorder(bst_iter, root);
    return bst_iter;
}

int bSTIteratorNext(BSTIterator* obj) {
    if (obj->head->right == NULL) {
        return -1;
    }
    int ret = obj->head->right->val;
    // for free
    obj->head->right->left = obj->head->left;
    obj->head->left = obj->head->right;

    obj->head->right = obj->head->right->right;
    return ret;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->head->right != NULL;
}

void bSTIteratorFree(BSTIterator* obj) {
    if (obj) {
        while (obj->head->left) {
            struct TreeNode* f = obj->head->left;
            obj->head->left = obj->head->left->left;
            free(f);
        }
        free(obj->head);
        free(obj);
    }
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/
```
### cpp [🔗](binary-search-tree-iterator.cpp) 
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) : vec_(0), index_(0) {
        std::function<void(TreeNode*)> inorder = [&,this](TreeNode *node) {
            if (node == nullptr) return;
            inorder(node->left);
            vec_.push_back(node->val);
            inorder(node->right);
        };
        inorder(root);
    }
    
    int next() {
        return vec_[index_++];
    }
    
    bool hasNext() {
        if (index_ == vec_.size()) {
            return false;
        }
        return true;
    }
private:
    vector<int> vec_;
    int index_;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```
### golang [🔗](binary-search-tree-iterator.go) 
```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type BSTIterator struct {
    root  *TreeNode
    stack []*TreeNode
}


func Constructor(root *TreeNode) BSTIterator {
    return BSTIterator{
        root: root,
    }
}


func (this *BSTIterator) Next() int {
    if !this.HasNext() {
        return -1
    }

    for this.root != nil {
        this.stack = append(this.stack, this.root)
        this.root = this.root.Left
    }
    topIndex := len(this.stack) - 1
    this.root = this.stack[topIndex]
    this.stack = this.stack[:topIndex]
    ret := this.root.Val
    this.root = this.root.Right
    return ret
}


func (this *BSTIterator) HasNext() bool {
    return this.root != nil || len(this.stack) != 0 
}


/**
 * Your BSTIterator object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */
```


## 相关话题



## 相似题目



## Links

- [Prev](../excel-sheet-column-number/README.md) 
- [Next](../second-highest-salary/README.md) 

