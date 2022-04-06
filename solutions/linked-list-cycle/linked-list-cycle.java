// @Title: Linked List Cycle
// @Author: colinjxc
// @Date: 2022-02-01T02:58:38+08:00
// @URL: https://leetcode-cn.com/problems/linked-list-cycle


/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            head = head.next;
            if (head == fast) {
                return true;
            }
        }
        return false;
    }
}
