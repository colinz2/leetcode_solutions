
# [设计哈希集合](https://leetcode-cn.com/problems/design-hashset)

## 题目描述

<p>不使用任何内建的哈希表库设计一个哈希集合（HashSet）。</p>

<p>实现 <code>MyHashSet</code> 类：</p>

<ul>
	<li><code>void add(key)</code> 向哈希集合中插入值 <code>key</code> 。</li>
	<li><code>bool contains(key)</code> 返回哈希集合中是否存在这个值 <code>key</code> 。</li>
	<li><code>void remove(key)</code> 将给定值 <code>key</code> 从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。</li>
</ul>
&nbsp;

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
<strong>输出：</strong>
[null, null, null, true, false, null, true, null, false]

<strong>解释：</strong>
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // 返回 True
myHashSet.contains(3); // 返回 False ，（未找到）
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // 返回 True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // 返回 False ，（已移除）</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= key &lt;= 10<sup>6</sup></code></li>
	<li>最多调用 <code>10<sup>4</sup></code> 次 <code>add</code>、<code>remove</code> 和 <code>contains</code></li>
</ul>


## 题解

### cpp [🔗](design-hashset.cpp) 
```cpp
class MyHashSet {
public:
    const size_t Kcap = 4096;

    int hash(int key) {
        return key % Kcap;
    }

public:
    MyHashSet() {
        v_.resize(Kcap);
    }
    
    void add(int key) {
        int index = hash(key);
        auto& list = v_[index];
        for (auto it = list.begin(); it != list.end(); it++) {
            if (*it == key) {
                return;
            }
        }
        list.push_front(key);
    }
    
    void remove(int key) {
        int index = hash(key);
        auto& list = v_[index];
        for (auto it = list.begin(); it != list.end(); it++) {
            if (*it == key) {
                list.erase(it);
                break;
            }
        }
        // 可以用 erase 删除 iterator
        //list.remove(key);
    }
    
    bool contains(int key) {
        int index = hash(key);
        auto& list = v_[index];
        for (auto it = list.begin(); it != list.end(); it++) {
            if (*it == key) {
                return true;
            }
        }
        return false;
    }
private:
    std::vector<std::list<int>> v_;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
```


## 相关话题

- [设计](../../tags/design.md) 
- [数组](../../tags/array.md) 
- [哈希表](../../tags/hash-table.md) 
- [链表](../../tags/linked-list.md) 
- [哈希函数](../../tags/hash-function.md) 


## 相似题目

- [设计哈希映射](../design-hashmap/README.md)  [Easy] 


## Links

- [Prev](../rotate-string/README.md) 
- [Next](../design-hashmap/README.md) 

