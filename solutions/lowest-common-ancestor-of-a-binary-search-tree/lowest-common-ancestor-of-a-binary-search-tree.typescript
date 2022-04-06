// @Title: Lowest Common Ancestor of a Binary Search Tree
// @Author: colinjxc
// @Date: 2022-02-01T04:59:20+08:00
// @URL: https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree


/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function lowestCommonAncestor(root: TreeNode | null, p: TreeNode | null, q: TreeNode | null): TreeNode | null {
	if (root != null) {
        if (root.val > p.val && root.val > q.val) {
            return lowestCommonAncestor(root.left, p, q)
        } else if (root.val < p.val && root.val < q.val) {
            return lowestCommonAncestor(root.right, p, q)
        }
    }
    return root
};
