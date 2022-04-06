// @Title: Binary Search Tree Iterator
// @Author: colinjxc
// @Date: 2022-02-17T02:10:53+08:00
// @URL: https://leetcode-cn.com/problems/binary-search-tree-iterator


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
