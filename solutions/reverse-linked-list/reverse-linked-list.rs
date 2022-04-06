// @Title: Reverse Linked List
// @Author: colinjxc
// @Date: 2022-02-01T15:17:20+08:00
// @URL: https://leetcode-cn.com/problems/reverse-linked-list


// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.is_none() { return None; }
        let mut prev = None;
        let mut current = head;
        while let Some(mut tmp) = current.take() {
	        let next = tmp.next.take();
	        tmp.next = prev.take();
	        prev = Some(tmp);
	        current = next;
        }
        prev
    }
}
