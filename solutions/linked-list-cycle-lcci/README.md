
# [](https://leetcode-cn.com/problems/linked-list-cycle-lcci)

## 题目描述



## 题解

### cpp [🔗](linked-list-cycle-lcci.cpp) 
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> listSet;
        while (head) {
            if (listSet.count(head) != 0) {
                return head;
            }
            listSet.insert(head);
            head = head->next; 
        }
        return nullptr;
    }
};
```
### golang [🔗](linked-list-cycle-lcci.go) 
```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func detectCycle(head *ListNode) *ListNode {
    nodeMap := make(map[*ListNode]struct{})
    for head != nil {
        if _, e := nodeMap[head]; e {
            return head;
        }
        nodeMap[head] = struct{}{}
        head = head.Next
    }   
    return nil
}
```


## 相关话题



## 相似题目



## Links

- [Prev](../is-unique-lcci/README.md) 
- [Next](../minimum-height-tree-lcci/README.md) 

