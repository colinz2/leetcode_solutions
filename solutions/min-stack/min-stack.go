// @Title: Min Stack
// @Author: realzhangm
// @Date: 2021-11-02T19:12:46+08:00
// @URL: https://leetcode-cn.com/problems/min-stack


type MinStack struct {
    data []int
}


func Constructor() MinStack {
    return MinStack {
        data : make([]int, 0, 512),
    }
}


func (this *MinStack) Push(val int)  {
    if len(this.data) == 0 {
        this.data = append(this.data, val, val)
    } else {
        min := this.GetMin()
        min = func(a, b int) int {
            if  a > b {
                return b
            }
            return a
        }(min, val)
        this.data = append(this.data, min, val)
    }
}


func (this *MinStack) Pop()  {
    dataSize := len(this.data)
    if dataSize < 2 {
        return
    }

    this.data = this.data[0: dataSize-2]
}


func (this *MinStack) Top() int {
    return this.data[len(this.data) - 1]
}


func (this *MinStack) GetMin() int {
    return this.data[len(this.data) - 2]
}


/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(val);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */
