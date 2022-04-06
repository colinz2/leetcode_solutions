// @Title: Copy List with Random Pointer
// @Author: colinjxc
// @Date: 2022-02-05T21:40:08+08:00
// @URL: https://leetcode-cn.com/problems/copy-list-with-random-pointer


"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        curr = head
        node_map = dict()
        while curr:
            node_map[curr] = Node(curr.val)
            curr = curr.next
        curr = head
        
        while curr:
            node = node_map[curr]
            if curr.next:
                node.next = node_map[curr.next]
            if curr.random:
                node.random = node_map[curr.random]
            curr = curr.next
        if head == None:
            return None
        return node_map[head]

