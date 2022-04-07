
# [](https://leetcode-cn.com/problems/linked-list-random-node)

## 题目描述



## 题解

### cpp [🔗](linked-list-random-node.cpp) 
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
    Solution(ListNode* head) {
        while (head) {
            vec_.push_back(head);
            head = head->next;
        }
    }
    
    int getRandom() {
        return vec_[rand() % vec_.size()]->val;
    }
private:
    std::vector<ListNode*> vec_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
```


## 相关话题



## 相似题目



## Links

- [Prev](../guess-number-higher-or-lower/README.md) 
- [Next](../ransom-note/README.md) 

