// @Title: Design Add and Search Words Data Structure
// @Author: colinjxc
// @Date: 2022-01-22T05:50:52+08:00
// @URL: https://leetcode-cn.com/problems/design-add-and-search-words-data-structure


class WordDictionary {
private:
    struct Node {
        int ref;
        std::map<char, Node*> next;

        Node* FindChild(char c) {
            auto it = next.find(c);
            if (it == next.end()) {
                return nullptr;
            }
            return it->second; 
        }

        void SetChild(char c, Node* node) {
            next[c] = node;
        }

        Node(): ref(0) {};
    };

public:
    WordDictionary() {

    }
    
    void addWord(string word) {
        Node* node = &root;
        for (auto c : word) {
            auto curr = node->FindChild(c);
            if (curr == nullptr) {
                curr = new Node();
                node->SetChild(c, curr);
            }
            node = curr;
        }
        node->ref++;
    }
    
    bool search(string word) {
        return search_(&root, word);
    }

    bool search_(Node* node, string word) {
        if (node == nullptr)
            return false;

        if (word.empty())
            return node->ref > 0;
        
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '.') {
                // how to iterator
                for (auto it = node->next.begin(); it != node->next.end(); it++) {
                    if (search_(it->second, word.substr(i+1))) {
                        return true;
                    }
                }
                return false;
            } else {
                return search_(node->FindChild(word[i]), word.substr(i+1));
            }

        }
        return false;
    }

private:
    Node root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
