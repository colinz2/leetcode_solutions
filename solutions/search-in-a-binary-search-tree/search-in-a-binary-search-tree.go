// @Title: Search in a Binary Search Tree
// @Author: colinjxc
// @Date: 2021-05-23T18:07:33+08:00
// @URL: https://leetcode-cn.com/problems/search-in-a-binary-search-tree


/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func searchBST(root *TreeNode, val int) *TreeNode {
	queue := list.New()
	node := queue.PushBack(root).Value.(*TreeNode)

	for queue.Len() != 0 {
		node = queue.Remove(queue.Front()).(*TreeNode)
		if node == nil || node.Val == val {
			break
		} else if val > node.Val {
			queue.PushBack(node.Right)
		} else {
			queue.PushBack(node.Left)
		}
	}
	return node
}
