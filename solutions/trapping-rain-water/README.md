
# [接雨水](https://leetcode-cn.com/problems/trapping-rain-water)

## 题目描述

<p>给定&nbsp;<code>n</code> 个非负整数表示每个宽度为 <code>1</code> 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/rainwatertrap.png" style="height: 161px; width: 412px;" /></p>

<pre>
<strong>输入：</strong>height = [0,1,0,2,1,0,1,3,2,1,2,1]
<strong>输出：</strong>6
<strong>解释：</strong>上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>height = [4,2,0,3,2,5]
<strong>输出：</strong>9
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == height.length</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= height[i] &lt;= 10<sup>5</sup></code></li>
</ul>


## 题解

### cpp [🔗](trapping-rain-water.cpp) 
```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int maxLeft = height[0];
        int maxRight = height[height.size()-1];

        int res = 0;
        while (left < right) {
            maxLeft = std::max(maxLeft, height[left]);
            maxRight = std::max(maxRight, height[right]);
            if (height[left] < height[right]) {
                res += maxLeft - height[left];
                left++;
            } else {
                res += maxRight - height[right];
                right--;
            }
        }
        return res;
    }
};
```


## 相关话题

- [栈](../../tags/stack.md) 
- [数组](../../tags/array.md) 
- [双指针](../../tags/two-pointers.md) 
- [动态规划](../../tags/dynamic-programming.md) 
- [单调栈](../../tags/monotonic-stack.md) 


## 相似题目

- [盛最多水的容器](../container-with-most-water/README.md)  [Medium] 
- [除自身以外数组的乘积](../product-of-array-except-self/README.md)  [Medium] 


## Links

- [Prev](../combination-sum/README.md) 
- [Next](../multiply-strings/README.md) 

