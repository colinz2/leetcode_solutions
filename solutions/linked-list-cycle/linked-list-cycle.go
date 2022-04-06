// @Title: Linked List Cycle
// @Author: colinjxc
// @Date: 2022-02-01T02:49:03+08:00
// @URL: https://leetcode-cn.com/problems/linked-list-cycle


/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func hasCycle(head *ListNode) bool {
    fast := head
    for fast != nil && fast.Next != nil {
        head = head.Next
        fast = fast.Next.Next
        if fast == head {
            return true
        }
    }
    return false
}
