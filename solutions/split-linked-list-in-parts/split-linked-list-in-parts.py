// @Title: Split Linked List in Parts
// @Author: colinjxc
// @Date: 2022-02-03T16:30:08+08:00
// @URL: https://leetcode-cn.com/problems/split-linked-list-in-parts


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: ListNode, k: int) -> List[ListNode]:
        res = [None for _ in range(k)]
        if head == None:
            return res

        list_len = 0
        curr = head
        while curr:
            curr = curr.next
            list_len += 1
        psize = list_len // k
        rsize = list_len % k

        curr = head
        for i in range(k):
            if curr == None:
                break

            res[i] = curr        
            j = 1
            while j < psize + (1 if i < rsize else 0):
                curr = curr.next
                j += 1
            
            if curr:
                next_node = curr.next
                curr.next = None
                curr = next_node
        
        return res
