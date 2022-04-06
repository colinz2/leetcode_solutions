// @Title: Linked List Cycle
// @Author: colinjxc
// @Date: 2022-02-01T02:56:58+08:00
// @URL: https://leetcode-cn.com/problems/linked-list-cycle


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        fast = head
        while fast != None and fast.next != None:
            fast = fast.next.next
            head = head.next
            if fast == head:
                return True
        return False
