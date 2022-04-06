
# [展开二维向量](https://leetcode-cn.com/problems/flatten-2d-vector)

## 题目描述

<p>请设计并实现一个能够展开二维向量的迭代器。该迭代器需要支持 <code>next</code> 和 <code>hasNext</code> 两种操作。</p>

<p> </p>

<p><strong>示例：</strong></p>

<pre>
Vector2D iterator = new Vector2D([[1,2],[3],[4]]);

iterator.next(); // 返回 1
iterator.next(); // 返回 2
iterator.next(); // 返回 3
iterator.hasNext(); // 返回 true
iterator.hasNext(); // 返回 true
iterator.next(); // 返回 4
iterator.hasNext(); // 返回 false
</pre>

<p> </p>

<p><strong>注意：</strong></p>

<ol>
	<li>请记得 <strong>重置 </strong>在 Vector2D 中声明的类变量（静态变量），因为类变量会 <strong>在多个测试用例中保持不变</strong>，影响判题准确。请 <a href="https://support.leetcode-cn.com/hc/kb/section/1071534/" target="_blank">查阅</a> 这里。</li>
	<li>你可以假定 <code>next()</code> 的调用总是合法的，即当 <code>next()</code> 被调用时，二维向量总是存在至少一个后续元素。</li>
</ol>

<p> </p>

<p><strong>进阶：</strong>尝试在代码中仅使用 <a href="http://www.cplusplus.com/reference/iterator/iterator/">C++ 提供的迭代器</a> 或 <a href="https://docs.oracle.com/javase/7/docs/api/java/util/Iterator.html">Java 提供的迭代器</a>。</p>


## 题解

### cpp [🔗](flatten-2d-vector.cpp) 
```cpp
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec) : i_(0), j_(0), vec_(&vec) {
        // 调整索引, 
        while (!vec_->empty() && vec_->at(i_).empty() && ++i_ < vec_->size()); 
    }

    int next() {
        if (!hasNext()) {
            throw std::out_of_range("vector2d out of range!"); 
            return -1;
        }
        int n = vec_->at(i_).at(j_);
        if (vec_->at(i_).size() == j_ + 1) {
            // 调整索引
            while (++i_ < vec_->size() && vec_->at(i_).empty());
            j_ = 0;
        } else {
            j_++;
        }
        return n;
    }
    
    bool hasNext() {
        if (i_ == vec_->size())
            return false;
        return true;
    }
private:
    size_t i_;
    size_t j_;
    vector<vector<int>>* vec_;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```


## 相关话题

- [设计](https://leetcode-cn.com/tag/design) 
- [数组](https://leetcode-cn.com/tag/array) 
- [双指针](https://leetcode-cn.com/tag/two-pointers) 
- [迭代器](https://leetcode-cn.com/tag/iterator) 


## 相似题目

- [二叉搜索树迭代器](../binary-search-tree-iterator/README.md)  [Medium] 


## Links

- [Prev](../group-shifted-strings/README.md) 
- [Next](../meeting-rooms/README.md) 

