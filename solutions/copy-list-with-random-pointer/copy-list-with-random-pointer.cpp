// @Title: Copy List with Random Pointer
// @Author: colinjxc
// @Date: 2022-02-05T22:00:53+08:00
// @URL: https://leetcode-cn.com/problems/copy-list-with-random-pointer


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> node_map;
        for (auto curr = head; curr; curr = curr->next) {
            node_map[curr] = new Node(curr->val);
        }
        for (auto curr = head; curr; curr = curr->next) {
            auto new_node = node_map[curr];
            new_node->random = node_map[curr->random];
            new_node->next = node_map[curr->next];
        }        
        return node_map[head];
    }
};
