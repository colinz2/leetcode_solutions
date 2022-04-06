
# [合并区间](https://leetcode-cn.com/problems/merge-intervals)

## 题目描述

<p>以数组 <code>intervals</code> 表示若干个区间的集合，其中单个区间为 <code>intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> 。请你合并所有重叠的区间，并返回&nbsp;<em>一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间</em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>intervals = [[1,3],[2,6],[8,10],[15,18]]
<strong>输出：</strong>[[1,6],[8,10],[15,18]]
<strong>解释：</strong>区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>intervals = [[1,4],[4,5]]
<strong>输出：</strong>[[1,5]]
<strong>解释：</strong>区间 [1,4] 和 [4,5] 可被视为重叠区间。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= intervals.length &lt;= 10<sup>4</sup></code></li>
	<li><code>intervals[i].length == 2</code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
</ul>


## 题解

### cpp [🔗](merge-intervals.cpp) 
```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return {};
        vector<vector<int>> res;
        std::sort(intervals.begin(), intervals.end());

        for (int i = 0, k = 0, end = 0; i < intervals.size(); ) {
            k = i + 1;
            end = intervals[i].back();
            while (k < intervals.size() && intervals[k].front() <= end) {
                end = std::max(end, intervals[k].back());
                k++;
            }
            res.push_back({intervals[i].front(), end});
            i = k;
        }

        return res;
    }
};
```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 
- [排序](https://leetcode-cn.com/tag/sorting) 


## 相似题目

- [会议室](../meeting-rooms/README.md)  [Easy] 


## Links

- [Prev](../jump-game/README.md) 
- [Next](../length-of-last-word/README.md) 

