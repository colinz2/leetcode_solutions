
# [](https://leetcode-cn.com/problems/design-compressed-string-iterator)

## 题目描述



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



## 相似题目



## Links

- [Prev](../valid-square/README.md) 
- [Next](../construct-string-from-binary-tree/README.md) 

