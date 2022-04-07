
# [“气球” 的最大数量](https://leetcode-cn.com/problems/maximum-number-of-balloons)

## 题目描述

<p>给你一个字符串&nbsp;<code>text</code>，你需要使用 <code>text</code> 中的字母来拼凑尽可能多的单词&nbsp;<strong>&quot;balloon&quot;（气球）</strong>。</p>

<p>字符串&nbsp;<code>text</code> 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词&nbsp;<strong>&quot;balloon&quot;</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/09/14/1536_ex1_upd.jpeg" style="height: 35px; width: 154px;"></strong></p>

<pre><strong>输入：</strong>text = &quot;nlaebolko&quot;
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/09/14/1536_ex2_upd.jpeg" style="height: 35px; width: 233px;"></strong></p>

<pre><strong>输入：</strong>text = &quot;loonbalxballpoon&quot;
<strong>输出：</strong>2
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>text = &quot;leetcode&quot;
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 10^4</code></li>
	<li><code>text</code>&nbsp;全部由小写英文字母组成</li>
</ul>


## 题解

### cpp [🔗](maximum-number-of-balloons.cpp) 
```cpp
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[128] = {0,};
        for (auto c : text) {
            freq[c]++;
        }
        int m1 = std::min(freq['l']/2, freq['o']/2);
        return std::min({freq['b'], freq['a'], freq['n'], m1});
    }
};
```


## 相关话题

- [哈希表](../../tags/hash-table.md) 
- [字符串](../../tags/string.md) 
- [计数](../../tags/counting.md) 


## 相似题目



## Links

- [Prev](../longest-common-subsequence/README.md) 
- [Next](../fizz-buzz-multithreaded/README.md) 

