
# [二叉搜索树迭代器](https://leetcode-cn.com/problems/binary-search-tree-iterator)

## 题目描述

实现一个二叉搜索树迭代器类<code>BSTIterator</code> ，表示一个按中序遍历二叉搜索树（BST）的迭代器：
<div class="original__bRMd">
<div>
<ul>
	<li><code>BSTIterator(TreeNode root)</code> 初始化 <code>BSTIterator</code> 类的一个对象。BST 的根节点 <code>root</code> 会作为构造函数的一部分给出。指针应初始化为一个不存在于 BST 中的数字，且该数字小于 BST 中的任何元素。</li>
	<li><code>boolean hasNext()</code> 如果向指针右侧遍历存在数字，则返回 <code>true</code> ；否则返回 <code>false</code> 。</li>
	<li><code>int next()</code>将指针向右移动，然后返回指针处的数字。</li>
</ul>

<p>注意，指针初始化为一个不存在于 BST 中的数字，所以对 <code>next()</code> 的首次调用将返回 BST 中的最小元素。</p>
</div>
</div>

<p>你可以假设 <code>next()</code> 调用总是有效的，也就是说，当调用 <code>next()</code> 时，BST 的中序遍历中至少存在一个下一个数字。</p>

<p> </p>

<p><strong>示例：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/25/bst-tree.png" style="width: 189px; height: 178px;" />
<pre>
<strong>输入</strong>
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
<strong>输出</strong>
[null, 3, 7, true, 9, true, 15, true, 20, false]

<strong>解释</strong>
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // 返回 3
bSTIterator.next();    // 返回 7
bSTIterator.hasNext(); // 返回 True
bSTIterator.next();    // 返回 9
bSTIterator.hasNext(); // 返回 True
bSTIterator.next();    // 返回 15
bSTIterator.hasNext(); // 返回 True
bSTIterator.next();    // 返回 20
bSTIterator.hasNext(); // 返回 False
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在范围 <code>[1, 10<sup>5</sup>]</code> 内</li>
	<li><code>0 <= Node.val <= 10<sup>6</sup></code></li>
	<li>最多调用 <code>10<sup>5</sup></code> 次 <code>hasNext</code> 和 <code>next</code> 操作</li>
</ul>

<p> </p>

<p><strong>进阶：</strong></p>

<ul>
	<li>你可以设计一个满足下述条件的解决方案吗？<code>next()</code> 和 <code>hasNext()</code> 操作均摊时间复杂度为 <code>O(1)</code> ，并使用 <code>O(h)</code> 内存。其中 <code>h</code> 是树的高度。</li>
</ul>


## 题解

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


## 相关话题

- [栈](../../tags/stack.md) 
- [树](../../tags/tree.md) 
- [设计](../../tags/design.md) 
- [二叉搜索树](../../tags/binary-search-tree.md) 
- [二叉树](../../tags/binary-tree.md) 
- [迭代器](../../tags/iterator.md) 


## 相似题目

- [二叉树的中序遍历](../binary-tree-inorder-traversal/README.md)  [Easy] 
- [展开二维向量](../flatten-2d-vector/README.md)  [Medium] 


## Links

- [Prev](../excel-sheet-column-number/README.md) 
- [Next](../second-highest-salary/README.md) 

