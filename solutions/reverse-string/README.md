
# [](https://leetcode-cn.com/problems/reverse-string)

## 题目描述



## 题解

### cpp [🔗](reverse-string.cpp) 
```cpp
class Solution {
public:
    string reverseString(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            std::swap(s[l++], s[r--]);
        }
        return s;
    }
};
```
### python3 [🔗](reverse-string.py) 
```python3
class Solution:
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        return s[::-1]
        
```


## 相关话题



## 相似题目



## Links

- [Prev](../integer-break/README.md) 
- [Next](../reverse-vowels-of-a-string/README.md) 

