
# [](https://leetcode-cn.com/problems/search-in-a-sorted-array-of-unknown-size)

## 题目描述



## 题解

### c [🔗](search-in-a-sorted-array-of-unknown-size.c) 
```c
/**
 * *********************************************************************
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * int getElement(ArrayReader *, int index);
 */

int search(struct ArrayReader* reader, int target) {
    int i = 0, j = 10e4+1;

    while (i < j) {
        int m = (i+j)>>1;
        int res = getElement(reader, m);
        if (res > target) {
            j = m;
        } else if (res < target) {
            i = m + 1;
        } else {
            return m;
        }
    }

    return -1;    
}
```
### cpp [🔗](search-in-a-sorted-array-of-unknown-size.cpp) 
```cpp
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int i = 0, j = 10e4;
        while (i < j) {
            int m = i + (j - i)/2;
            if (reader.get(m) == INT_MAX) {
                j = m;
            } else {
                i = m + 1;
            }
        }
        
        j = 0;

        while (j < i) {
            int m = j + (i - i)/2;
            if ((reader.get(m) < target)) {
                j = m + 1;
            } else if ((reader.get(m) > target)) {
                i = m;
            } else {
                return m;
            }
        }
        return -1;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../search-in-a-binary-search-tree/README.md) 
- [Next](../kth-largest-element-in-a-stream/README.md) 

