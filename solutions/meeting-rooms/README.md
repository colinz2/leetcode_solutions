
# [会议室](https://leetcode-cn.com/problems/meeting-rooms)

## 题目描述

<p>给定一个会议时间安排的数组 <code>intervals</code> ，每个会议时间都会包括开始和结束的时间 <code>intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> ，请你判断一个人是否能够参加这里面的全部会议。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>intervals = [[0,30],[5,10],[15,20]]
<strong>输出</strong>：false
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>intervals = [[7,10],[2,4]]
<strong>输出</strong>：true
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= intervals.length <= 10<sup>4</sup></code></li>
	<li><code>intervals[i].length == 2</code></li>
	<li><code>0 <= start<sub>i</sub> < end<sub>i</sub> <= 10<sup>6</sup></code></li>
</ul>


## 题解

### golang [🔗](meeting-rooms.go) 
```golang
func canAttendMeetings(intervals [][]int) bool {
    sort.Slice(intervals, func(i, j int) bool {
        return intervals[i][0] < intervals[j][0]
    })
    for i := 0; i < len(intervals)-1; i++ {
        cur, next := intervals[i][1], intervals[i+1][0]
        if cur > next {
            return false
        }
    }
    return true
}
```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 
- [排序](https://leetcode-cn.com/tag/sorting) 


## 相似题目

- [合并区间](../merge-intervals/README.md)  [Medium] 


## Links

- [Prev](../flatten-2d-vector/README.md) 
- [Next](../factor-combinations/README.md) 

