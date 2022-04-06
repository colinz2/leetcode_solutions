
# [字符串中的单词数](https://leetcode-cn.com/problems/number-of-segments-in-a-string)

## 题目描述

<p>统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。</p>

<p>请注意，你可以假定字符串里不包括任何不可打印的字符。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> &quot;Hello, my name is John&quot;
<strong>输出:</strong> 5
<strong>解释: </strong>这里的单词是指连续的不是空格的字符，所以 &quot;Hello,&quot; 算作 1 个单词。
</pre>


## 题解

### cpp [🔗](number-of-segments-in-a-string.cpp) 
```cpp
class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) 
            res += s[i] != ' ' && (i + 1 == s.size() || s[i + 1] == ' ');
        return res;
    }
};


```


## 相关话题

- [字符串](https://leetcode-cn.com/tag/string) 


## 相似题目



## Links

- [Prev](../add-strings/README.md) 
- [Next](../arranging-coins/README.md) 

