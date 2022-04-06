// @Title: Rotate List
// @Author: colinjxc
// @Date: 2022-02-03T18:47:48+08:00
// @URL: https://leetcode-cn.com/problems/rotate-list


/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func rotateRight(head *ListNode, k int) *ListNode {
    last := head
    if last == nil {
        return nil
    }
    listLen := 1
    for last.Next != nil {
        listLen++
        last = last.Next;
    }
    last.Next = head;
    for i := 0; i < listLen - (k % listLen); i++ {
        last = last.Next
    }
    head = last.Next
    last.Next = nil
    return head 
}
