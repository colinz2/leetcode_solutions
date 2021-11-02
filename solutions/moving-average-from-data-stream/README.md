
# [数据流中的移动平均值](https://leetcode-cn.com/problems/moving-average-from-data-stream)

## 题目描述

<p>给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算其所有整数的移动平均值。</p>

<p>实现 <code>MovingAverage</code> 类：</p>

<ul>
	<li><code>MovingAverage(int size)</code> 用窗口大小 <code>size</code> 初始化对象。</li>
	<li><code>double next(int val)</code> 计算并返回数据流中最后 <code>size</code> 个值的移动平均值。</li>
</ul>

<p> </p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["MovingAverage", "next", "next", "next", "next"]
[[3], [1], [10], [3], [5]]
<strong>输出：</strong>
[null, 1.0, 5.5, 4.66667, 6.0]

<strong>解释：</strong>
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // 返回 1.0 = 1 / 1
movingAverage.next(10); // 返回 5.5 = (1 + 10) / 2
movingAverage.next(3); // 返回 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // 返回 6.0 = (10 + 3 + 5) / 3
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= size <= 1000</code></li>
	<li><code>-10<sup>5</sup> <= val <= 10<sup>5</sup></code></li>
	<li>最多调用 <code>next</code> 方法 <code>10<sup>4</sup></code> 次</li>
</ul>


## 题解

### golang [🔗](moving-average-from-data-stream.go) 
```golang
type MovingAverage struct {
    cnt     int
    data    []int
}


func Constructor(size int) MovingAverage {
    return MovingAverage{
        data : make([]int, size),
    }
}


func (this *MovingAverage) Next(val int) float64 {
    dataSize := len(this.data)
    this.data[this.cnt % dataSize] = val

    var sum int
    for _, v := range this.data {
        sum += v
    }
    this.cnt++

    if this.cnt > dataSize {
        return float64(sum) / float64(dataSize) 
    } else {
        return float64(sum) / float64(this.cnt)
    }
}


/**
 * Your MovingAverage object will be instantiated and called as such:
 * obj := Constructor(size);
 * param_1 := obj.Next(val);
 */
```


## 相关话题

- [设计](https://leetcode-cn.com/tag/design) 
- [队列](https://leetcode-cn.com/tag/queue) 
- [数组](https://leetcode-cn.com/tag/array) 
- [数据流](https://leetcode-cn.com/tag/data-stream) 


## 相似题目



## Links

- [Prev](../first-bad-version/README.md) 
- [Next](../guess-number-higher-or-lower/README.md) 

