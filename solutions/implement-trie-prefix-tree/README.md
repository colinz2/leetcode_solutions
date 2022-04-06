
# [实现 Trie (前缀树)](https://leetcode-cn.com/problems/implement-trie-prefix-tree)

## 题目描述

<p><strong><a href="https://baike.baidu.com/item/字典树/9825209?fr=aladdin" target="_blank">Trie</a></strong>（发音类似 "try"）或者说 <strong>前缀树</strong> 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。</p>

<p>请你实现 Trie 类：</p>

<ul>
	<li><code>Trie()</code> 初始化前缀树对象。</li>
	<li><code>void insert(String word)</code> 向前缀树中插入字符串 <code>word</code> 。</li>
	<li><code>boolean search(String word)</code> 如果字符串 <code>word</code> 在前缀树中，返回 <code>true</code>（即，在检索之前已经插入）；否则，返回 <code>false</code> 。</li>
	<li><code>boolean startsWith(String prefix)</code> 如果之前已经插入的字符串 <code>word</code> 的前缀之一为 <code>prefix</code> ，返回 <code>true</code> ；否则，返回 <code>false</code> 。</li>
</ul>

<p> </p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入</strong>
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
<strong>输出</strong>
[null, null, true, false, true, null, true]

<strong>解释</strong>
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // 返回 True
trie.search("app");     // 返回 False
trie.startsWith("app"); // 返回 True
trie.insert("app");
trie.search("app");     // 返回 True
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= word.length, prefix.length <= 2000</code></li>
	<li><code>word</code> 和 <code>prefix</code> 仅由小写英文字母组成</li>
	<li><code>insert</code>、<code>search</code> 和 <code>startsWith</code> 调用次数 <strong>总计</strong> 不超过 <code>3 * 10<sup>4</sup></code> 次</li>
</ul>


## 题解

### cpp [🔗](implement-trie-prefix-tree.cpp) 
```cpp
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
```


## 相关话题

- [设计](https://leetcode-cn.com/tag/design) 
- [字典树](https://leetcode-cn.com/tag/trie) 
- [哈希表](https://leetcode-cn.com/tag/hash-table) 
- [字符串](https://leetcode-cn.com/tag/string) 


## 相似题目

- [添加与搜索单词 - 数据结构设计](../design-add-and-search-words-data-structure/README.md)  [Medium] 


## Links

- [Prev](../reverse-linked-list/README.md) 
- [Next](../minimum-size-subarray-sum/README.md) 

