
# [](https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof)

## 题目描述



## 题解

### cpp [🔗](ti-huan-kong-ge-lcof.cpp) 
```cpp
class Solution {
public:
    string replaceSpace(string s) {
        int cnt = 0, len = s.size();
        for (auto &c : s) {
            if (c == ' ') {
                cnt++;
            }
        }
        s.resize(len + 2*cnt);
        for (int i = s.size() - 1, j = len - 1;  i != j; i--, j-- ) {
            if (s[j] != ' ') {
                s[i] = s[j];
            } else {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        }

        return s;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/README.md) 
- [Next](../cong-wei-dao-tou-da-yin-lian-biao-lcof/README.md) 

