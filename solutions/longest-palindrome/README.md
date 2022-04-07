
# [](https://leetcode-cn.com/problems/longest-palindrome)

## 题目描述



## 题解

### c [🔗](longest-palindrome.c) 
```c
int longestPalindrome(char * s){
    int seen[128] = {0,};
    int strlen = 0;
    while (*s) seen[*s++]++, strlen++;
    int ocnt = 0;
    for (int i = 'a'; i <= 'z'; i++) {
        ocnt += seen[i] % 2;
    }
    for (int i = 'A'; i <= 'Z'; i++) {
        ocnt += seen[i] % 2;
    }
    if (ocnt > 0) ocnt--;
    
    return strlen - ocnt;
}
```
### cpp [🔗](longest-palindrome.cpp) 
```cpp
class Solution {
public:


    int longestPalindrome(string s) {

        int n = s.size();
        if (n == 0) return 0;
        int table[52] = {0};
            
        for (int i = 0; i < n; i++)
        {
            int index = int(s[i] - 'A');
            if (s[i] >= 'a')    index -= 6;
            table[index]++;
        }

        int even = 0;
        int odd = 0;
        for (int i = 0; i < 52; i++)
        {
            even += table[i] / 2 * 2;
            odd += table[i] % 2;     
        }
        
        odd = odd > 0 ? 1: 0;
        return even + odd;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../decode-string/README.md) 
- [Next](../fizz-buzz/README.md) 

