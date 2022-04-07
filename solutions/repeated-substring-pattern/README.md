
# [](https://leetcode-cn.com/problems/repeated-substring-pattern)

## 题目描述



## 题解

### cpp [🔗](repeated-substring-pattern.cpp) 
```cpp
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        string nextStr = str;
        int len = str.length();
        if(len < 1) return false;
        for(int i = 1; i <= len / 2; i++){
            if(len % i == 0){
                nextStr = leftShift(str, i);
                if(nextStr == str) return true;
            }
        }
        return false;
    }
    
    string leftShift(string &str, int l){
        string ret = str.substr(l);
        ret += str.substr(0, l);
        return ret;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../assign-cookies/README.md) 
- [Next](../hamming-distance/README.md) 

