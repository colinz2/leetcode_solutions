// @Title: Linked List Cycle LCCI
// @Author: colinjxc
// @Date: 2022-02-04T01:05:10+08:00
// @URL: https://leetcode-cn.com/problems/linked-list-cycle-lcci


/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func detectCycle(head *ListNode) *ListNode {
    nodeMap := make(map[*ListNode]struct{})
    for head != nil {
        if _, e := nodeMap[head]; e {
            return head;
        }
        nodeMap[head] = struct{}{}
        head = head.Next
    }   
    return nil
}
