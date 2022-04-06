
# [设计哈希映射](https://leetcode-cn.com/problems/design-hashmap)

## 题目描述

<p>不使用任何内建的哈希表库设计一个哈希映射（HashMap）。</p>

<p>实现 <code>MyHashMap</code> 类：</p>

<ul>
	<li><code>MyHashMap()</code> 用空映射初始化对象</li>
	<li><code>void put(int key, int value)</code> 向 HashMap 插入一个键值对 <code>(key, value)</code> 。如果 <code>key</code> 已经存在于映射中，则更新其对应的值 <code>value</code> 。</li>
	<li><code>int get(int key)</code> 返回特定的 <code>key</code> 所映射的 <code>value</code> ；如果映射中不包含 <code>key</code> 的映射，返回 <code>-1</code> 。</li>
	<li><code>void remove(key)</code> 如果映射中存在 <code>key</code> 的映射，则移除 <code>key</code> 和它所对应的 <code>value</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入</strong>：
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
<strong>输出</strong>：
[null, null, null, 1, -1, null, 1, null, -1]

<strong>解释</strong>：
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // myHashMap 现在为 [[1,1]]
myHashMap.put(2, 2); // myHashMap 现在为 [[1,1], [2,2]]
myHashMap.get(1);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,2]]
myHashMap.get(3);    // 返回 -1（未找到），myHashMap 现在为 [[1,1], [2,2]]
myHashMap.put(2, 1); // myHashMap 现在为 [[1,1], [2,1]]（更新已有的值）
myHashMap.get(2);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,1]]
myHashMap.remove(2); // 删除键为 2 的数据，myHashMap 现在为 [[1,1]]
myHashMap.get(2);    // 返回 -1（未找到），myHashMap 现在为 [[1,1]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= key, value &lt;= 10<sup>6</sup></code></li>
	<li>最多调用 <code>10<sup>4</sup></code> 次 <code>put</code>、<code>get</code> 和 <code>remove</code> 方法</li>
</ul>


## 题解

### cpp [🔗](design-hashmap.cpp) 
```cpp
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
```


## 相关话题

- [设计](https://leetcode-cn.com/tag/design) 
- [数组](https://leetcode-cn.com/tag/array) 
- [哈希表](https://leetcode-cn.com/tag/hash-table) 
- [链表](https://leetcode-cn.com/tag/linked-list) 
- [哈希函数](https://leetcode-cn.com/tag/hash-function) 


## 相似题目

- [设计哈希集合](../design-hashset/README.md)  [Easy] 


## Links

- [Prev](../design-hashset/README.md) 
- [Next](../unique-morse-code-words/README.md) 

