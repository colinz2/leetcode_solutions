
# [](https://leetcode-cn.com/problems/valid-anagram)

## 题目描述



## 题解

### cpp [🔗](valid-anagram.cpp) 
```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[256] = {0,};

        for (auto &c : s) cnt[c]++;
        for (auto &c : t) cnt[c]--;
        return all_of(cnt+'a', cnt+'z' + 1, [](int c){ return  c == 0; });
    }
};
```
### golang [🔗](valid-anagram.go) 
```golang
func isAnagram(s string, t string) bool {
    cntMap := make(map[rune]int)
    if len(s) != len(t) {
        return false
    }

    for _, c := range s {
        cntMap[c]++
    }

    for _, c := range t {
        cntMap[c]--
    }

    for _, v := range cntMap {
        if v != 0 {
            return false
        }
    }

    return true
}
```
### python3 [🔗](valid-anagram.py) 
```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)
```
### c [🔗](valid-anagram.c) 
```c
bool is_all_zero(int *array, int len) {
    for (int i = 0; i < len; i++) {
        if (array[i] != 0) return false;
    }
    return true;
}

bool isAnagram(char * s, char * t){
    int find[256] = {0};
    int s_len = 0, t_len = 0;

    if (s == NULL || t == NULL)
        return false;

    while (*s != '\0') {
        find[*s++ - 'a']++;
        s_len++;
    }
    while (*t != '\0') {
        find[*t++ - 'a']--;
        t_len++;
    } 
    return s_len == t_len && is_all_zero(find, 26);
}
```


## 相关话题



## 相似题目



## Links

- [Prev](../sliding-window-maximum/README.md) 
- [Next](../group-shifted-strings/README.md) 

