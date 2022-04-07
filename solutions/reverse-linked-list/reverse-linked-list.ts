// @Title: Reverse Linked List
// @Author: colinjxc
// @Date: 2022-02-01T15:06:32+08:00
// @URL: https://leetcode-cn.com/problems/reverse-linked-list


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

function reverseList(head: ListNode | null): ListNode | null {
    if (head == null || head.next == null) {
        return head;
    }
    let newNode = reverseList(head.next)
    head.next.next = head
    head.next = null
    return newNode
};
