
# [柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram)

## 题目描述

<p>给定 <em>n</em> 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。</p>

<p>求在该柱状图中，能够勾勒出来的矩形的最大面积。</p>

<p> </p>

<p><strong>示例 1:</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2021/01/04/histogram.jpg" /></p>

<pre>
<strong>输入：</strong>heights = [2,1,5,6,2,3]
<strong>输出：</strong>10
<strong>解释：</strong>最大的矩形为图中红色区域，面积为 10
</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2021/01/04/histogram-1.jpg" /></p>

<pre>
<strong>输入：</strong> heights = [2,4]
<b>输出：</b> 4</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= heights.length <=10<sup>5</sup></code></li>
	<li><code>0 <= heights[i] <= 10<sup>4</sup></code></li>
</ul>


## 题解

### cpp [🔗](largest-rectangle-in-histogram.cpp) 
```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> st;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int cur = st.top(); st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                res = max(res, heights[cur] * width);
            }
            st.push(i);
        }
        return res;
    }
};
```


## 相关话题

- [栈](../../tags/stack.md) 
- [数组](../../tags/array.md) 
- [单调栈](../../tags/monotonic-stack.md) 


## 相似题目



## Links

- [Prev](../remove-duplicates-from-sorted-list/README.md) 
- [Next](../partition-list/README.md) 

