
# [有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram)

## 题目描述

<p>给定两个字符串 <code><em>s</em></code> 和 <code><em>t</em></code> ，编写一个函数来判断 <code><em>t</em></code> 是否是 <code><em>s</em></code> 的字母异位词。</p>

<p><strong>注意：</strong>若 <code><em>s</em></code> 和 <code><em>t</em></code><em> </em>中每个字符出现的次数都相同，则称 <code><em>s</em></code> 和 <code><em>t</em></code><em> </em>互为字母异位词。</p>

<p> </p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> <em>s</em> = "anagram", <em>t</em> = "nagaram"
<strong>输出:</strong> true
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> <em>s</em> = "rat", <em>t</em> = "car"
<strong>输出: </strong>false</pre>

<p> </p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 <= s.length, t.length <= 5 * 10<sup>4</sup></code></li>
	<li><code>s</code> 和 <code>t</code> 仅包含小写字母</li>
</ul>

<p> </p>

<p><strong>进阶: </strong>如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？</p>


## 题解

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


## 相关话题

- [哈希表](../../tags/hash-table.md) 
- [字符串](../../tags/string.md) 
- [排序](../../tags/sorting.md) 


## 相似题目

- [字母异位词分组](../group-anagrams/README.md)  [Medium] 
- [回文排列](../palindrome-permutation/README.md)  [Easy] 


## Links

- [Prev](../sliding-window-maximum/README.md) 
- [Next](../group-shifted-strings/README.md) 

