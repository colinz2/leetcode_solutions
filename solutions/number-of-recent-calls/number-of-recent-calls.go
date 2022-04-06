// @Title: Number of Recent Calls
// @Author: colinjxc
// @Date: 2022-01-31T17:26:03+08:00
// @URL: https://leetcode-cn.com/problems/number-of-recent-calls


type RecentCounter struct {
    slice []int
}


func Constructor() RecentCounter {
    return RecentCounter {
        slice : make([]int, 0, 30000),
    }    
}


func (this *RecentCounter) Ping(t int) int {
    this.slice = append(this.slice, t)
    for this.slice[0] + 3000 < t {
        this.slice = this.slice[1:]
    }
    return len(this.slice)
}


/**
 * Your RecentCounter object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ping(t);
 */
