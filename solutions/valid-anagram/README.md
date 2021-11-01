
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

### cpp [🔗](valid-anagram.cpp) 
```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[256] = {0,};

        for (auto &c : s) cnt[c - 'a']++;
        for (auto &c : t) cnt[c - 'a']--;
        return all_of(cnt, cnt+32, [](int c){ return  c == 0; });
    }
};
```


## 相关话题

- [哈希表](https://leetcode-cn.com/tag/hash-table) 
- [字符串](https://leetcode-cn.com/tag/string) 
- [排序](https://leetcode-cn.com/tag/sorting) 


## 相似题目



## Links

- [Prev](../invert-binary-tree/README.md) 
- [Next](../add-digits/README.md) 

