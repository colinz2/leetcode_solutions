
# [滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum)

## 题目描述

<p>给你一个整数数组 <code>nums</code>，有一个大小为&nbsp;<code>k</code><em>&nbsp;</em>的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 <code>k</code>&nbsp;个数字。滑动窗口每次只向右移动一位。</p>

<p>返回 <em>滑动窗口中的最大值 </em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,3,-1,-3,5,3,6,7], k = 3
<b>输出：</b>[3,3,5,5,6,7]
<b>解释：</b>
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       <strong>3</strong>
 1 [3  -1  -3] 5  3  6  7       <strong>3</strong>
 1  3 [-1  -3  5] 3  6  7      <strong> 5</strong>
 1  3  -1 [-3  5  3] 6  7       <strong>5</strong>
 1  3  -1  -3 [5  3  6] 7       <strong>6</strong>
 1  3  -1  -3  5 [3  6  7]      <strong>7</strong>
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1], k = 1
<b>输出：</b>[1]
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup>&nbsp;&lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>


## 题解

### cpp [🔗](sliding-window-maximum.cpp) 
```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<std::pair<int, int>> pq;
        for (int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }
        vector<int> res = {pq.top().first};

        // [l, r] window
        int l = 1, r = k;
        while (r < nums.size()) {
            while (!pq.empty() && pq.top().second < l) {
                pq.pop();
            }
            pq.push({nums[r], r});
            res.push_back(pq.top().first);
            l++;
            r++;
        }
        return res;
    }
};
```


## 相关话题

- [队列](../../tags/queue.md) 
- [数组](../../tags/array.md) 
- [滑动窗口](../../tags/sliding-window.md) 
- [单调队列](../../tags/monotonic-queue.md) 
- [堆（优先队列）](../../tags/heap-priority-queue.md) 


## 相似题目

- [最小栈](../min-stack/README.md)  [Easy] 


## Links

- [Prev](../product-of-array-except-self/README.md) 
- [Next](../valid-anagram/README.md) 

