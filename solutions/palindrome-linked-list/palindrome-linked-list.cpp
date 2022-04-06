// @Title: Palindrome Linked List
// @Author: colinjxc
// @Date: 2022-02-05T18:28:19+08:00
// @URL: https://leetcode-cn.com/problems/palindrome-linked-list


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
    bool isPalindrome(ListNode* head) {
        std::vector<int> vec;
        while (head) {
            vec.push_back(head->val);
            head = head->next;
        }
        int i = 0, j = vec.size() - 1;
        while (i < j) {
            if (vec[i++] != vec[j--]) {
                return false;
            }
        }
        return true;
    }
};
