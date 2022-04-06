// @Title: Implement Trie (Prefix Tree)
// @Author: colinjxc
// @Date: 2022-01-22T03:51:18+08:00
// @URL: https://leetcode-cn.com/problems/implement-trie-prefix-tree


class Trie {
private:
    struct TrieNode {
        uint32_t chr;
        bool end;
        map<uint32_t, TrieNode*> children;

        TrieNode(uint32_t c) {
            chr = c;
            end = false;
        }
        
        TrieNode* findChild(uint32_t c) {
            auto it = children.find(c);
            if (it == children.end()) {
                return nullptr;
            }
            return it->second; 
        }

        void insertChild(uint32_t c, TrieNode* node) {
            children[c] = node;
        }
    };

public:
    Trie() : root_(-1){

    }
    
    void insert(string word) {
        TrieNode* node = &root_;
        for (auto c: word) {
            auto curr = node->findChild(c);
            if (curr == nullptr) {
                curr = new TrieNode(c);
                node->insertChild(c, curr);           
            }
            node = curr;  
        }
        node->end = true;
    }
    
    bool search(string word) {
        TrieNode* node = &root_;
        for (auto c : word) {
            node = node->findChild(c);
            if (node == nullptr) {
                return false;
            }
        }
        return node->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = &root_;
        for (auto c : prefix) {
            node = node->findChild(c);
            if (node == nullptr) {
                return false;
            }
        }
        return true;
    }
private:
    TrieNode root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
