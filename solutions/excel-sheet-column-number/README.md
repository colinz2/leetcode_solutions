
# [Excel 表列序号](https://leetcode-cn.com/problems/excel-sheet-column-number)

## 题目描述

<p>给你一个字符串&nbsp;<code>columnTitle</code> ，表示 Excel 表格中的列名称。返回 <em>该列名称对应的列序号</em>&nbsp;。</p>

<p>例如：</p>

<pre>
A -&gt; 1
B -&gt; 2
C -&gt; 3
...
Z -&gt; 26
AA -&gt; 27
AB -&gt; 28 
...</pre>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> columnTitle = "A"
<strong>输出:</strong> 1
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入: </strong>columnTitle = "AB"
<strong>输出:</strong> 28
</pre>

<p><strong>示例&nbsp;3:</strong></p>

<pre>
<strong>输入: </strong>columnTitle = "ZY"
<strong>输出:</strong> 701</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= columnTitle.length &lt;= 7</code></li>
	<li><code>columnTitle</code> 仅由大写英文组成</li>
	<li><code>columnTitle</code> 在范围 <code>["A", "FXSHRXW"]</code> 内</li>
</ul>


## 题解

### cpp [🔗](excel-sheet-column-number.cpp) 
```cpp
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum = 0;
        for (auto c : columnTitle) {
            if (sum >= (INT_MAX - (c-'A'+1)) / 26) {
                return INT_MAX;
            }
            sum = ('Z'-'A' + 1) * sum + c - 'A' + 1;
        }
        return sum;
    }
};
```


## 相关话题

- [数学](../../tags/math.md) 
- [字符串](../../tags/string.md) 


## 相似题目



## Links

- [Prev](../majority-element/README.md) 
- [Next](../binary-search-tree-iterator/README.md) 

