
# [](https://leetcode-cn.com/problems/reverse-linked-list)

## 题目描述



## 题解

### rust [🔗](reverse-linked-list.rs) 
```rust
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
```
### typescript [🔗](reverse-linked-list.ts) 
```typescript
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function reverseList(head: ListNode | null): ListNode | null {
    if (head == null || head.next == null) {
        return head;
    }
    let newNode = reverseList(head.next)
    head.next.next = head
    head.next = null
    return newNode
};
```
### c [🔗](reverse-linked-list.c) 
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* new_head = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}
```
### cpp [🔗](reverse-linked-list.cpp) 
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr) {
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
```
### golang [🔗](reverse-linked-list.go) 
```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    var pre, next *ListNode = nil, nil
    for head != nil {
        next, head.Next = head.Next, pre
        pre , head = head, next
    }
    return pre
}
```
### java [🔗](reverse-linked-list.java) 
```java
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
    public ListNode reverseList(ListNode head) {
        ListNode pre = null, next = null;
        while (head != null) {
            next = head.next;
            head.next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
}
```
### python3 [🔗](reverse-linked-list.py) 
```python3
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
```


## 相关话题



## 相似题目



## Links

- [Prev](../isomorphic-strings/README.md) 
- [Next](../implement-trie-prefix-tree/README.md) 

