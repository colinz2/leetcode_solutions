
# [](https://leetcode-cn.com/problems/maximum-twin-sum-of-a-linked-list)

## 题目描述



## 题解

### cpp [🔗](maximum-twin-sum-of-a-linked-list.cpp) 
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
    int pairSum(ListNode* head) {
        vector<int> vec;
        for (auto p = head; p; p = p->next) {
            vec.push_back(p->val);
        }
        int sum = 0;
        for (int i = 0; i < vec.size()/2; i++) {
            sum = std::max(sum, vec[i] + vec[vec.size()-1-i]);
        }
        return sum;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../delete-the-middle-node-of-a-linked-list/README.md) 
- [Next](../count-elements-with-strictly-smaller-and-greater-elements/README.md) 

