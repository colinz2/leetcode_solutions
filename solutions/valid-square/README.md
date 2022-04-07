
# [有效的正方形](https://leetcode-cn.com/problems/valid-square)

## 题目描述

<p>给定2D空间中四个点的坐标&nbsp;<code>p1</code>,&nbsp;<code>p2</code>,&nbsp;<code>p3</code>&nbsp;和&nbsp;<code>p4</code>，如果这四个点构成一个正方形，则返回 <code>true</code> 。</p>

<p>点的坐标&nbsp;<code>p<sub>i</sub></code> 表示为 <code>[xi, yi]</code> 。输入 <strong>不是</strong> 按任何顺序给出的。</p>

<p>一个 <strong>有效的正方形</strong> 有四条等边和四个等角(90度角)。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
<strong>输出:</strong> True
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入：</strong>p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
<b>输出：</b>false
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<b>输入：</b>p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
<b>输出：</b>true
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>p1.length == p2.length == p3.length == p4.length == 2</code></li>
	<li><code>-10<sup>4</sup>&nbsp;&lt;= x<sub>i</sub>, y<sub>i</sub>&nbsp;&lt;= 10<sup>4</sup></code></li>
</ul>


## 题解

### cpp [🔗](valid-square.cpp) 
```cpp
class Solution {
public:
    int Distance(vector<int>& x, vector<int>& y) {
        int d = abs(x[0] - y[0])*abs(x[0] - y[0]) + 
                    abs(x[1] - y[1])*abs(x[1] - y[1]);
        return d;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> d;
        d.push_back(Distance(p1, p2));
        d.push_back(Distance(p1, p3));
        d.push_back(Distance(p1, p4));
        d.push_back(Distance(p2, p3));
        d.push_back(Distance(p2, p4));
        d.push_back(Distance(p3, p4));
        
        sort(d.begin(), d.end());
        for (int i = 1; i < 4; i++) {
             if (d[i - 1] != d[i]) return false;
        }
        
        if (d[3] == d[4]) return false;
        if (d[4] != d[5]) return false;
        
        return true;
    }
};
```


## 相关话题

- [几何](../../tags/geometry.md) 
- [数学](../../tags/math.md) 


## 相似题目



## Links

- [Prev](../delete-operation-for-two-strings/README.md) 
- [Next](../design-compressed-string-iterator/README.md) 

