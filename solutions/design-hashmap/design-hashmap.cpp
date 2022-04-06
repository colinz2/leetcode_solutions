// @Title: Design HashMap
// @Author: colinjxc
// @Date: 2022-01-22T19:46:04+08:00
// @URL: https://leetcode-cn.com/problems/design-hashmap


class MyHashMap {
public:
    struct Node {
        int key;
        int value;
        Node* next;
        
        Node(int k, int v) : key(k), value(v), next(nullptr) {}
    };

private:
    const size_t kCap = 5120;
    int hash(int key) {
        return (key) % kCap;
    }

public:
    MyHashMap() : v_(kCap, nullptr) {
    }
        
    void put(int key, int value) {
        Node** node = &v_[hash(key)];
        if (*node == nullptr) {
            *node = new Node(key, value);
            return;
        }

        Node* curr = *node;
        while (curr) {
            if (curr->key == key) {
                curr->value = value;
                return;
            }
            curr = curr->next;
        }
        // 插入到头节点, curr 是当前的头指针。容易写错
        curr = (*node);
        *node = new Node(key, value);
        (*node)->next = curr;
    }
    
    int get(int key) {
        Node* node = v_[hash(key)];
        while (node) {
            if (node->key == key) 
                return node->value;
            node = node->next;
        }
        return -1;
    }
    
    void remove(int key) {
        Node** node = &v_[hash(key)];
        while (*node) {
            if ((*node)->key == key) {
                // 删除注意，这块容易写错
                Node* next = (*node)->next;
                delete (*node);
                *node = next;
                return;
            }
            node = &((*node)->next);
        }
    }

private:
    std::vector<Node*> v_;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
