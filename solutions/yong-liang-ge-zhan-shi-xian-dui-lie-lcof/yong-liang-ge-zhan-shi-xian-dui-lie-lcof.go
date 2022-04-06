// @Title: 用两个栈实现队列 LCOF
// @Author: colinjxc
// @Date: 2021-07-19T22:24:42+08:00
// @URL: https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof


type CQueue struct {
    a []int
    b []int
}


func Constructor() CQueue {
    return CQueue{}
}


func (this *CQueue) AppendTail(value int)  {
    this.a = append(this.a, value)
}


func (this *CQueue) DeleteHead() int {
    bLen := len(this.b)
    if len(this.a) + bLen == 0 {
        return -1
    }

    if bLen == 0 {
        bLen = len(this.a)
        for i := bLen - 1; i >= 0; i-- {
            this.b = append(this.b, this.a[i])
        }
        this.a = this.a[:0]
    }

    res := this.b[bLen - 1]
    this.b = this.b[:bLen - 1]
    return res
}


/**
 * Your CQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AppendTail(value);
 * param_2 := obj.DeleteHead();
 */
