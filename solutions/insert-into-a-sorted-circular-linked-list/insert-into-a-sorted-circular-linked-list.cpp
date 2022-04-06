// @Title: Insert into a Sorted Circular Linked List
// @Author: colinjxc
// @Date: 2022-02-05T23:15:14+08:00
// @URL: https://leetcode-cn.com/problems/insert-into-a-sorted-circular-linked-list


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        Node* curr = head;
        while (curr->next != head) {
            if (curr->val <= insertVal && insertVal <= curr->next->val) {
                break;
            }
            if (curr->val > curr->next->val) {
                if (curr->val <= insertVal || curr->next->val >= insertVal) {
                    break;
                }
            }
            curr = curr->next;
        }
        Node* node = new Node(insertVal, curr->next);
        curr->next = node;
        return head;
    }
};
