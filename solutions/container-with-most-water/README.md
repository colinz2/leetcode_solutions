
# [盛最多水的容器](https://leetcode-cn.com/problems/container-with-most-water)

## 题目描述

<p>给定一个长度为 <code>n</code> 的整数数组&nbsp;<code>height</code>&nbsp;。有&nbsp;<code>n</code>&nbsp;条垂线，第 <code>i</code> 条线的两个端点是&nbsp;<code>(i, 0)</code>&nbsp;和&nbsp;<code>(i, height[i])</code>&nbsp;。</p>

<p>找出其中的两条线，使得它们与&nbsp;<code>x</code>&nbsp;轴共同构成的容器可以容纳最多的水。</p>

<p>返回容器可以储存的最大水量。</p>

<p><strong>说明：</strong>你不能倾斜容器。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/07/25/question_11.jpg" /></p>

<pre>
<strong>输入：</strong>[1,8,6,2,5,4,8,3,7]
<strong>输出：</strong>49 
<strong>解释：</strong>图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为&nbsp;49。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>height = [1,1]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == height.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= height[i] &lt;= 10<sup>4</sup></code></li>
</ul>


## 题解

### cpp [🔗](container-with-most-water.cpp) 
```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int j = 0, k = height.size() - 1;
        int max_area = 0;
        while (j < k) {
            int min_height = std::min(height[k], height[j]);
            int area = (k - j) * min_height;
            max_area = std::max(max_area, area);
            if (min_height == height[k]) {
                k--;
            } else {
                j++;
            }
        }
        return max_area;
    }
};
```


## 相关话题

- [贪心](../../tags/greedy.md) 
- [数组](../../tags/array.md) 
- [双指针](../../tags/two-pointers.md) 


## 相似题目

- [接雨水](../trapping-rain-water/README.md)  [Hard] 


## Links

- [Prev](../palindrome-number/README.md) 
- [Next](../roman-to-integer/README.md) 

