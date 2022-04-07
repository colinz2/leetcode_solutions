
# [根据字符出现频率排序](https://leetcode-cn.com/problems/sort-characters-by-frequency)

## 题目描述

<p>给定一个字符串 <code>s</code> ，根据字符出现的 <strong>频率</strong> 对其进行 <strong>降序排序</strong> 。一个字符出现的 <strong>频率</strong> 是它出现在字符串中的次数。</p>

<p>返回 <em>已排序的字符串&nbsp;</em>。如果有多个答案，返回其中任何一个。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入: </strong>s = "tree"
<strong>输出: </strong>"eert"
<strong>解释: </strong>'e'出现两次，'r'和't'都只出现一次。
因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入: </strong>s = "cccaaa"
<strong>输出: </strong>"cccaaa"
<strong>解释: </strong>'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
注意"cacaca"是不正确的，因为相同的字母必须放在一起。
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入: </strong>s = "Aabb"
<strong>输出: </strong>"bbAa"
<strong>解释: </strong>此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
注意'A'和'a'被认为是两种不同的字符。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;由大小写英文字母和数字组成</li>
</ul>


## 题解

### cpp [🔗](sort-characters-by-frequency.cpp) 
```cpp
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cmap;
        for (auto &c : s) {
            cmap[c]++; 
        }
        priority_queue< pair<int, char> > pq; 
        for (auto &it :cmap) {
            pq.push(make_pair(it.second, it.first));
        }
        string res;
        while (pq.size() > 0) {
            auto top = pq.top();
            res.append(top.first, top.second);
            pq.pop();
        }
        return res;
    }
};
```


## 相关话题

- [哈希表](../../tags/hash-table.md) 
- [字符串](../../tags/string.md) 
- [桶排序](../../tags/bucket-sort.md) 
- [计数](../../tags/counting.md) 
- [排序](../../tags/sorting.md) 
- [堆（优先队列）](../../tags/heap-priority-queue.md) 


## 相似题目

- [前 K 个高频元素](../top-k-frequent-elements/README.md)  [Medium] 
- [字符串中的第一个唯一字符](../first-unique-character-in-a-string/README.md)  [Easy] 


## Links

- [Prev](../find-all-numbers-disappeared-in-an-array/README.md) 
- [Next](../assign-cookies/README.md) 

