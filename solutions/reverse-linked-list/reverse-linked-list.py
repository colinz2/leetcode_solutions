// @Title: Reverse Linked List
// @Author: colinjxc
// @Date: 2022-02-01T14:51:16+08:00
// @URL: https://leetcode-cn.com/problems/reverse-linked-list


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head == None or head.next == None :
            return head
        new_head = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return new_head 
