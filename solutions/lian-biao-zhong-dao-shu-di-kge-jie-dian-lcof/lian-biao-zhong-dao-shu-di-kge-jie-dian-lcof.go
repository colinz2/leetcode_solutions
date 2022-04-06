// @Title: 链表中倒数第k个节点 LCOF
// @Author: colinjxc
// @Date: 2021-07-20T12:42:11+08:00
// @URL: https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof


/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getKthFromEnd(head *ListNode, k int) *ListNode {
    fast := head
    slow := head
    for k > 0 && fast != nil {
        fast = fast.Next
        k--
    }

    for fast != nil {
        fast = fast.Next
        slow = slow.Next
    }

    return slow
}
