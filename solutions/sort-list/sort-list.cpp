// @Title: Sort List
// @Author: colinjxc
// @Date: 2022-02-04T01:57:40+08:00
// @URL: https://leetcode-cn.com/problems/sort-list


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
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }

    ListNode* sortList(ListNode* head, ListNode* tail) {
        if (head == NULL) {
            return head;
        }
        if (head->next == tail) {
            // set to nullptr
            head->next = nullptr;
            return head;
        }
        ListNode *fast = head, *slow = head;
        while (fast != tail && fast->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        }

        auto l1 = sortList(head, slow);
        auto l2 = sortList(slow, tail);
        return merge(l1, l2);
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* l3 = &dummy;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                l3->next = l2;
                l2 = l2->next;
            } else {
                l3->next = l1;
                l1 = l1->next;
            }
            l3 = l3->next;
        }
        if (l1) {
            l3->next = l1;
        } else {
            l3->next = l2;
        }

        return dummy.next;
    }
};
