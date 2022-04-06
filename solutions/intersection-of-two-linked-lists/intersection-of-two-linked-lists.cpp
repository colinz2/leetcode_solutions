// @Title: Intersection of Two Linked Lists
// @Author: colinjxc
// @Date: 2018-12-07T01:22:18+08:00
// @URL: https://leetcode-cn.com/problems/intersection-of-two-linked-lists


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* pA = headA;
        ListNode* pB = headB;
        while(pA || pB){

            if(pA == pB)
                return pA;

            if(pA) pA = pA->next;
            else pA = headB;

            if(pB) pB = pB->next;
            else pB = headA;
        }

        return NULL;
    }
};
