// @Title: Linked List Cycle
// @Author: colinjxc
// @Date: 2022-02-01T03:04:23+08:00
// @URL: https://leetcode-cn.com/problems/linked-list-cycle


/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function hasCycle(head: ListNode | null): boolean {
    let fast = head
    while (fast != null && fast.next != null) {
        fast = fast.next.next
        head = head.next
        if (head === fast) {
            return true
        }
    }
    return false
};
