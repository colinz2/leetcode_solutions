// @Title: Add Two Numbers
// @Author: colinjxc
// @Date: 2021-05-20T16:14:37+08:00
// @URL: https://leetcode-cn.com/problems/add-two-numbers


/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	head := new(ListNode)
	carry, sum, curr := 0, 0, head

	for l1 != nil || l2 != nil || carry != 0 {
		if l1 != nil {
			sum += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			sum += l2.Val
			l2 = l2.Next
		}
		curr.Next = &ListNode{
			Val:  sum % 10,
			Next: nil,
		}
		carry = sum / 10
		curr = curr.Next
		sum = carry
	}

	return head.Next
}

