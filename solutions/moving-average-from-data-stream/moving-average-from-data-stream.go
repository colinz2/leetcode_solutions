// @Title: Moving Average from Data Stream
// @Author: colinjxc
// @Date: 2021-11-02T19:50:53+08:00
// @URL: https://leetcode-cn.com/problems/moving-average-from-data-stream


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
