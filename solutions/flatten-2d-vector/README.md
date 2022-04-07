
# [](https://leetcode-cn.com/problems/flatten-2d-vector)

## 题目描述



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



## 相似题目



## Links

- [Prev](../group-shifted-strings/README.md) 
- [Next](../meeting-rooms/README.md) 

