// @Title: Kth Node From End of List LCCI
// @Author: colinjxc
// @Date: 2022-02-04T14:10:22+08:00
// @URL: https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def kthToLast(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: int
        """
        node_list = []
        while head:
            node_list.append(head.val)
            head = head.next
        return node_list[-k]
