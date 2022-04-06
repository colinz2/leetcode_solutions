
# [设计跳表](https://leetcode-cn.com/problems/design-skiplist)

## 题目描述

<p>不使用任何库函数，设计一个 <strong>跳表</strong> 。</p>

<p><strong>跳表</strong> 是在 <code>O(log(n))</code> 时间内完成增加、删除、搜索操作的数据结构。跳表相比于树堆与红黑树，其功能与性能相当，并且跳表的代码长度相较下更短，其设计思想与链表相似。</p>

<p>例如，一个跳表包含 <code>[30, 40, 50, 60, 70, 90]</code> ，然后增加 <code>80</code>、<code>45</code> 到跳表中，以下图的方式操作：</p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/09/27/1506_skiplist.gif" /><br />
<small>Artyom Kalinin [CC BY-SA 3.0], via <a href="https://commons.wikimedia.org/wiki/File:Skip_list_add_element-en.gif" target="_blank" title="Artyom Kalinin [CC BY-SA 3.0 (https://creativecommons.org/licenses/by-sa/3.0)], via Wikimedia Commons">Wikimedia Commons</a></small></p>

<p>跳表中有很多层，每一层是一个短的链表。在第一层的作用下，增加、删除和搜索操作的时间复杂度不超过 <code>O(n)</code>。跳表的每一个操作的平均时间复杂度是 <code>O(log(n))</code>，空间复杂度是 <code>O(n)</code>。</p>

<p>了解更多 :&nbsp;<a href="https://en.wikipedia.org/wiki/Skip_list" target="_blank">https://en.wikipedia.org/wiki/Skip_list</a></p>

<p>在本题中，你的设计应该要包含这些函数：</p>

<ul>
	<li><code>bool search(int target)</code> : 返回target是否存在于跳表中。</li>
	<li><code>void add(int num)</code>:&nbsp;插入一个元素到跳表。</li>
	<li><code>bool erase(int num)</code>: 在跳表中删除一个值，如果&nbsp;<code>num</code>&nbsp;不存在，直接返回false. 如果存在多个&nbsp;<code>num</code>&nbsp;，删除其中任意一个即可。</li>
</ul>

<p>注意，跳表中可能存在多个相同的值，你的代码需要处理这种情况。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<b>输入</b>
["Skiplist", "add", "add", "add", "search", "add", "search", "erase", "erase", "search"]
[[], [1], [2], [3], [0], [4], [1], [0], [1], [1]]
<strong>输出</strong>
[null, null, null, null, false, null, true, false, true, false]

<strong>解释</strong>
Skiplist skiplist = new Skiplist();
skiplist.add(1);
skiplist.add(2);
skiplist.add(3);
skiplist.search(0);   // 返回 false
skiplist.add(4);
skiplist.search(1);   // 返回 true
skiplist.erase(0);    // 返回 false，0 不在跳表中
skiplist.erase(1);    // 返回 true
skiplist.search(1);   // 返回 false，1 已被擦除
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>0 &lt;= num, target &lt;= 2 * 10<sup>4</sup></code></li>
	<li>调用<code>search</code>, <code>add</code>, &nbsp;<code>erase</code>操作次数不大于&nbsp;<code>5 * 10<sup>4</sup></code>&nbsp;</li>
</ul>


## 题解

### cpp [🔗](design-skiplist.cpp) 
```cpp
#define kMaxLevel 16
#define N 999

struct Node {
  int key;
  vector<Node*> next;

  Node* Next(int level) {
      return next[level];
  }

  void SetNext(int level, Node* node) {
      next[level] = node;
  }

  int NextSize() {
      return next.size();
  }

  Node(int val, int maxlevel) : key(val), next(maxlevel, nullptr) {};
};

class Skiplist {
 private:
  int max_height_;
  Node* head_;

 public:
  Skiplist() : max_height_(1) {
    head_ = new Node(0, kMaxLevel);
    srand(0);
  }

  Node* findGreaterOrEqual(const int key, Node* prev[] = nullptr) {  // for insert
    Node* ptr = head_;
    int level = max_height_ - 1;
    while (true) {
      Node* next = ptr->Next(level);
      if (next != nullptr && next->key < key) {
        // same level
        ptr = next; 
      } else {
        if (prev != nullptr) prev[level] = ptr;
        if (level == 0) {
          return next;
        } else {
          level--;
        }
      }
    }
  }

  int getRandLevel(float factor = 0.5) {
    int level = 1;
    while ((rand() % N) / N > factor && level < kMaxLevel) {
      level++;
    }
    return level;
  }

  bool search(int target) {
    Node* temp = findGreaterOrEqual(target);
    if (temp && temp->key == target) {
      return true;
    } else {
      return false;
    }
  }

  void add(int num) {
    Node* prev[kMaxLevel];
    findGreaterOrEqual(num, prev);
    int randlevel = getRandLevel();
    if (randlevel > max_height_) {
      for (int i = max_height_ - 1; i < randlevel; i++) {
        prev[i] = head_;
      }
      max_height_ = randlevel;
    }
    Node* newNode = new Node(num, randlevel);
    for (int i = 0; i < max_height_; i++) {
      newNode->SetNext(i, prev[i]->Next(i));
      prev[i]->SetNext(i, newNode);
    }
  }

  bool erase(int num) {
    Node* prev[kMaxLevel];
    Node* temp = findGreaterOrEqual(num, prev);
    if (temp == nullptr || temp->key != num) {
      return false;
    }

    for (int i = 0; i < temp->NextSize(); i++) {
      prev[i]->SetNext(i, temp->Next(i));
    }
    delete temp;
    while (max_height_ > 1 && head_->Next(max_height_ - 1) == nullptr) {
        max_height_--; 
    }
    return true;
  }
};

```
### java [🔗](design-skiplist.java) 
```java
class Skiplist {
        /**
         * 最大层数
         */
        private static int DEFAULT_MAX_LEVEL = 32;
        /**
         * 随机层数概率，也就是随机出的层数，在 第1层以上(不包括第一层)的概率，层数不超过maxLevel，层数的起始号为1
         */
        private static double DEFAULT_P_FACTOR = 0.25;

        Node head = new Node(null,DEFAULT_MAX_LEVEL); //头节点

        int currentLevel = 1; //表示当前nodes的实际层数，它从1开始


        public Skiplist() {
        }

        public boolean search(int target) {
            Node searchNode = head;
            for (int i = currentLevel-1; i >=0; i--) {
                searchNode = findClosest(searchNode, i, target);
                if (searchNode.next[i]!=null && searchNode.next[i].value == target){
                    return true;
                }
            }
            return false;
        }

        /**
         *
         * @param num
         */
        public void add(int num) {
            int level = randomLevel();
            Node updateNode = head;
            Node newNode = new Node(num,level);
            // 计算出当前num 索引的实际层数，从该层开始添加索引
            for (int i = currentLevel-1; i>=0; i--) {
                //找到本层最近离num最近的list
                updateNode = findClosest(updateNode,i,num);
                if (i<level){
                    if (updateNode.next[i]==null){
                        updateNode.next[i] = newNode;
                    }else{
                        Node temp = updateNode.next[i];
                        updateNode.next[i] = newNode;
                        newNode.next[i] = temp;
                    }
                }
            }
            if (level > currentLevel){ //如果随机出来的层数比当前的层数还大，那么超过currentLevel的head 直接指向newNode
                for (int i = currentLevel; i < level; i++) {
                    head.next[i] = newNode;
                }
                currentLevel = level;
            }

        }

        public boolean erase(int num) {
            boolean flag = false;
            Node searchNode = head;
            for (int i = currentLevel-1; i >=0; i--) {
                searchNode = findClosest(searchNode, i, num);
                if (searchNode.next[i]!=null && searchNode.next[i].value == num){
                    //找到该层中该节点
                    searchNode.next[i] = searchNode.next[i].next[i];
                    flag = true;
                    continue;
                }
            }
            return flag;
        }

        /**
         * 找到level层 value 大于node 的节点
         * @param node
         * @param levelIndex
         * @param value
         * @return
         */
        private Node findClosest(Node node,int levelIndex,int value){
            while ((node.next[levelIndex])!=null && value >node.next[levelIndex].value){
                node = node.next[levelIndex];
            }
            return node;
        }


        /**
         * 随机一个层数
         */
        private static int randomLevel(){
            int level = 1;
            while (Math.random()<DEFAULT_P_FACTOR && level<DEFAULT_MAX_LEVEL){
                level ++ ;
            }
            return level;
        }


        class Node{
            Integer value;
            Node[] next;

            public Node(Integer value,int size) {
                this.value = value;
                this.next = new Node[size];
            }

            @Override
            public String toString() {
                return String.valueOf(value);
            }
        }

    }


/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist obj = new Skiplist();
 * boolean param_1 = obj.search(target);
 * obj.add(num);
 * boolean param_3 = obj.erase(num);
 */
```


## 相关话题

- [设计](https://leetcode-cn.com/tag/design) 
- [链表](https://leetcode-cn.com/tag/linked-list) 


## 相似题目



## Links

- [Prev](../fizz-buzz-multithreaded/README.md) 
- [Next](../the-dining-philosophers/README.md) 

