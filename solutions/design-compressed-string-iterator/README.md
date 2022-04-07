
# [迭代压缩字符串](https://leetcode-cn.com/problems/design-compressed-string-iterator)

## 题目描述

<p>设计并实现一个迭代压缩字符串的数据结构。给定的压缩字符串的形式是，每个字母后面紧跟一个正整数，表示该字母在原始未压缩字符串中出现的次数。</p>

<p>设计一个数据结构，它支持如下两种操作：&nbsp;<code>next</code>&nbsp;和&nbsp;<code>hasNext</code>。</p>

<ul>
	<li><code>next()</code> - 如果原始字符串中仍有未压缩字符，则返回<strong>下一个字符</strong>，否则返回<strong>空格</strong>。</li>
	<li><code>hasNext()</code> - 如果原始字符串中存在未压缩的的字母，则返回true，否则返回<code>false</code>。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["StringIterator", "next", "next", "next", "next", "next", "next", "hasNext", "next", "hasNext"]
[["L1e2t1C1o1d1e1"], [], [], [], [], [], [], [], [], []]
<b>输出：</b>
[null, "L", "e", "e", "t", "C", "o", true, "d", true]

<strong>解释：</strong>
StringIterator stringIterator = new StringIterator("L1e2t1C1o1d1e1");
stringIterator.next(); // 返回 "L"
stringIterator.next(); // 返回 "e"
stringIterator.next(); // 返回 "e"
stringIterator.next(); // 返回 "t"
stringIterator.next(); // 返回 "C"
stringIterator.next(); // 返回 "o"
stringIterator.hasNext(); // 返回 True
stringIterator.next(); // 返回 "d"
stringIterator.hasNext(); // 返回 True</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;compressedString.length &lt;= 1000</code></li>
	<li><code>compressedString</code>&nbsp;由小写字母、大写字母和数字组成。</li>
	<li>在&nbsp;<code>compressedString</code>&nbsp;中，单个字符的重复次数在&nbsp;<code>[1,10 ^9]</code>&nbsp;范围内。</li>
	<li><code>next</code>&nbsp;和&nbsp;<code>hasNext</code>&nbsp;的操作数最多为&nbsp;<code>100</code>&nbsp;。</li>
</ul>


## 题解

### cpp [🔗](design-compressed-string-iterator.cpp) 
```cpp
class StringIterator {
public:
    StringIterator(string compressedString) {
        str_ = list<int>(compressedString.begin(), compressedString.end());
        last_ = 0;
        last_cnt_ = 0;
    }
    
    char next() {
        if (!hasNext()) {
            return 0x20;
        }

        if (last_cnt_) {
            --last_cnt_;
            return last_;
        }

        if (!isdigit(str_.front())) {
            last_ = str_.front();
            str_.erase(str_.begin());
            return last_;
        }

        auto it = str_.begin();
        for (; it != str_.end() && isdigit(*it); it++) {
            last_cnt_ = last_cnt_ *10 + (*it - '0');
        }
        --last_cnt_;
        str_.erase(str_.begin(), it);
        if (last_cnt_ == 0) {
            return next();
        } else {
            --last_cnt_;
        }

        return last_;
    }
    
    bool hasNext() {
       return str_.size() != 0 || last_cnt_ > 0;
    }
private:
    char last_;
    char last_cnt_;
    std::list<int> str_;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```


## 相关话题

- [设计](https://leetcode-cn.com/tag/design) 
- [数组](https://leetcode-cn.com/tag/array) 
- [哈希表](https://leetcode-cn.com/tag/hash-table) 
- [字符串](https://leetcode-cn.com/tag/string) 
- [迭代器](https://leetcode-cn.com/tag/iterator) 


## 相似题目

- [LRU 缓存](../lru-cache/README.md)  [Medium] 
- [压缩字符串](../string-compression/README.md)  [Medium] 


## Links

- [Prev](../valid-square/README.md) 
- [Next](../construct-string-from-binary-tree/README.md) 

