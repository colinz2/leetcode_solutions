
# [每日温度](https://leetcode-cn.com/problems/daily-temperatures)

## 题目描述

<p>请根据每日 <code>气温</code> 列表 <code>temperatures</code> ，<span style="font-size:10.5pt"><span style="font-family:Calibri"><span style="font-size:10.5000pt"><span style="font-family:宋体"><font face="宋体">请计算在每一天需要等几天才会有更高的温度</font></span></span></span></span>。如果气温在这之后都不会升高，请在该位置用 <code>0</code> 来代替。</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> <code>temperatures</code> = [73,74,75,71,69,72,76,73]
<strong>输出:</strong> [1,1,4,2,1,1,0,0]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> temperatures = [30,40,50,60]
<strong>输出:</strong> [1,1,1,0]
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> temperatures = [30,60,90]
<strong>输出: </strong>[1,1,0]</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= temperatures.length <= 10<sup>5</sup></code></li>
	<li><code>30 <= temperatures[i] <= 100</code></li>
</ul>


## 题解

### cpp [🔗](daily-temperatures.cpp) 
```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // 单调栈，保存位置
        int len = temperatures.size();
        vector<int> res(len, 0);
        vector<int> st(len, 0);

        int stLen = 0;

        for (int i = 0; i < len; i++) {
            while (stLen > 0 && temperatures[i] > temperatures[st[stLen-1]]) {
                res[st[stLen-1]] = i - st[stLen-1];
                stLen--;
            }
            st[stLen++] = i;
        }

        return res;
    }
};
```


## 相关话题

- [栈](https://leetcode-cn.com/tag/stack) 
- [数组](https://leetcode-cn.com/tag/array) 
- [单调栈](https://leetcode-cn.com/tag/monotonic-stack) 


## 相似题目

- [下一个更大元素 I](../next-greater-element-i/README.md)  [Easy] 


## Links

- [Prev](../redundant-connection/README.md) 
- [Next](../maximum-depth-of-n-ary-tree/README.md) 

