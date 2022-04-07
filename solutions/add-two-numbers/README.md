
# [](https://leetcode-cn.com/problems/add-two-numbers)

## 题目描述



## 题解

### cpp [🔗](add-two-numbers.cpp) 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* l3 = &dummy;
        int add = 0;
        while (l1 || l2 || add) {
            if (l1) {
                add += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                add += l2->val;
                l2 = l2->next;
            }
            l3->next = new ListNode(add % 10);
            l3 = l3->next;
            add = add / 10; 
        }
        return dummy.next;
    }
};
```
### golang [🔗](add-two-numbers.go) 
```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	head := new(ListNode)
	carry, sum, curr := 0, 0, head

	for l1 != nil || l2 != nil || carry != 0 {
		if l1 != nil {
			sum += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			sum += l2.Val
			l2 = l2.Next
		}
		curr.Next = &ListNode{
			Val:  sum % 10,
			Next: nil,
		}
		carry = sum / 10
		curr = curr.Next
		sum = carry
	}

	return head.Next
}

```


## 相关话题



## 相似题目



## Links

- [Prev](../two-sum/README.md) 
- [Next](../longest-substring-without-repeating-characters/README.md) 

