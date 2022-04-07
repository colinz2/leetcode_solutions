
# [](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters)

## 题目描述



## 题解

### cpp [🔗](longest-substring-without-repeating-characters.cpp) 
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool exists[256] = {false};
        int left = 0, right = 0;
        int max_len = 0;

        while (right < s.size()) {
            int next = s[right];
            if (!exists[next]) {
                exists[s[right]] = true;
                max_len = std::max(max_len, right - left + 1);
                right++;
            } else {
                exists[s[left]] = false;
                left++;
            }
        }
        return max_len;
    }
};
```
### c [🔗](longest-substring-without-repeating-characters.c) 
```c
int lengthOfLongestSubstring(char * s){
    int left = 0;
    int right = 0;
    int max_len = 0;

    bool exist[256] = {false,};

    while (*(s+right)) {
        if (!exist[*(s+right)]) {
            exist[*(s+right)] = true;
            if (right - left + 1 > max_len) {
                max_len = right - left + 1;
            }
            right++;
        } else {
            exist[*(s+left)] = false;
            left++;
        }
    }
    return max_len;
}
```


## 相关话题



## 相似题目



## Links

- [Prev](../add-two-numbers/README.md) 
- [Next](../median-of-two-sorted-arrays/README.md) 

