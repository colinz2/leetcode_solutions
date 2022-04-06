// @Title: Odd Even Linked List
// @Author: colinjxc
// @Date: 2022-02-03T14:26:17+08:00
// @URL: https://leetcode-cn.com/problems/odd-even-linked-list


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if head == None:
            return head
        odd = head
        even = head.next
        even_head = even
        while even and even.next and odd.next:
            odd.next = odd.next.next
            even.next = even.next.next
            odd = odd.next
            even = even.next
        odd.next = even_head
        return head        
