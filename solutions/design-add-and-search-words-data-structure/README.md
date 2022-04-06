
# [添加与搜索单词 - 数据结构设计](https://leetcode-cn.com/problems/design-add-and-search-words-data-structure)

## 题目描述

<p>请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。</p>

<p>实现词典类 <code>WordDictionary</code> ：</p>

<ul>
	<li><code>WordDictionary()</code> 初始化词典对象</li>
	<li><code>void addWord(word)</code> 将 <code>word</code> 添加到数据结构中，之后可以对它进行匹配</li>
	<li><code>bool search(word)</code> 如果数据结构中存在字符串与&nbsp;<code>word</code> 匹配，则返回 <code>true</code> ；否则，返回&nbsp; <code>false</code> 。<code>word</code> 中可能包含一些 <code>'.'</code> ，每个&nbsp;<code>.</code> 都可以表示任何一个字母。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
<strong>输出：</strong>
[null,null,null,null,false,true,true,true]

<strong>解释：</strong>
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // 返回 False
wordDictionary.search("bad"); // 返回 True
wordDictionary.search(".ad"); // 返回 True
wordDictionary.search("b.."); // 返回 True
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 25</code></li>
	<li><code>addWord</code> 中的 <code>word</code> 由小写英文字母组成</li>
	<li><code>search</code> 中的 <code>word</code> 由 '.' 或小写英文字母组成</li>
	<li>最多调用 <code>10<sup>4</sup></code> 次 <code>addWord</code> 和 <code>search</code></li>
</ul>


## 题解

### cpp [🔗](design-add-and-search-words-data-structure.cpp) 
```cpp
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
```


## 相关话题

- [深度优先搜索](https://leetcode-cn.com/tag/depth-first-search) 
- [设计](https://leetcode-cn.com/tag/design) 
- [字典树](https://leetcode-cn.com/tag/trie) 
- [字符串](https://leetcode-cn.com/tag/string) 


## 相似题目

- [实现 Trie (前缀树)](../implement-trie-prefix-tree/README.md)  [Medium] 


## Links

- [Prev](../minimum-size-subarray-sum/README.md) 
- [Next](../house-robber-ii/README.md) 

