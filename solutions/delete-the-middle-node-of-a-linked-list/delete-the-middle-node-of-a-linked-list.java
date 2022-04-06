// @Title: Delete the Middle Node of a Linked List
// @Author: colinjxc
// @Date: 2022-02-04T00:31:36+08:00
// @URL: https://leetcode-cn.com/problems/delete-the-middle-node-of-a-linked-list


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */


class Solution {
    public ListNode deleteMiddle(ListNode head) {
        //快慢指针
        ListNode slow = head,fast = head.next;
        if(fast == null) return null;
        while(fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        slow.next = slow.next.next;
        return head;
    }
}
