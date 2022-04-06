// @Title: Happy Number
// @Author: colinjxc
// @Date: 2021-07-17T15:25:02+08:00
// @URL: https://leetcode-cn.com/problems/happy-number


func isHappy(n int) bool {
    slow, fast := n, calc(n)
    // 快慢指针， 如果成环快的一定能追的上慢的
    for slow != 1 && slow != fast {
        slow = calc(slow) 
        fast = calc(calc(fast))                                    
    } 
    return fast == 1
}

func calc(n int) int {
    res := 0
    for n > 0 {
        res += (n%10) * (n%10)
        n = n / 10                                    
    }
    return res
}
