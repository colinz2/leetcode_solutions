// @Title: LRU Cache
// @Author: colinjxc
// @Date: 2022-01-22T00:49:17+08:00
// @URL: https://leetcode-cn.com/problems/lru-cache


class LRUCache {
public:
    template <typename K, typename V>
    struct Node {
        K key;
        V value;
        Node<K,V>* next;
        Node<K,V>* prev;

        Node<K,V> (K k,V v):key(k), value(v), next(nullptr), prev(nullptr) {
        }
    };
    using LruNode = Node<int,int>;
public:
    LRUCache(int capacity) :cap_(capacity), size_(0), head_(0, 0) {
        head_.next = &head_;
        head_.prev = &head_;
    }
    
    int get(int key) {
        auto it = table_.find(key);
        if (it == table_.end()) {
            return -1;
        }
        LruNode* node = it->second;
        // LRU update
        removeNode(node);
        updateNode(node);

        return node->value;
    }
    
    void put(int key, int value) {
        LruNode* node = nullptr;
        auto it = table_.find(key);
        if (it == table_.end()) {
            node = new LruNode(key, value);
            table_[key] = node;
            size_++;
            // LRU update
            updateNode(node);
            if (size_ > cap_) {
                // LRU erase
                LruNode* rmNode = head_.prev;
                removeNode(rmNode);
                table_.erase(rmNode->key);
                delete rmNode;
                size_--;
            }

        } else {
            node = it->second;
            node->value = value;
            // LRU update
            removeNode(node);
            updateNode(node);
        }
    }

    void updateNode(LruNode* node) {
        node->prev = &head_;
        node->next = head_.next;
        head_.next->prev = node;
        head_.next = node;
    }

    void removeNode(LruNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

private:
    int cap_;
    int size_;
    LruNode head_;
    unordered_map<int, LruNode*> table_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
