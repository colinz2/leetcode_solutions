// @Title: Reverse Linked List
// @Author: colinjxc
// @Date: 2022-02-01T15:01:01+08:00
// @URL: https://leetcode-cn.com/problems/reverse-linked-list


/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    var pre, next *ListNode = nil, nil
    for head != nil {
        next, head.Next = head.Next, pre
        pre , head = head, next
    }
    return pre
}
