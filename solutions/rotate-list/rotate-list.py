// @Title: Rotate List
// @Author: colinjxc
// @Date: 2022-02-03T19:32:35+08:00
// @URL: https://leetcode-cn.com/problems/rotate-list


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head == None:
            return head
        last = head
        list_len = 1
        while last.next:
            last = last.next
            list_len += 1
        # link to head
        last.next = head
        for _ in range(0, list_len - (k % list_len)):
            last = last.next
        head = last.next
        last.next = None
        return head
