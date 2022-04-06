// @Title: Daily Temperatures
// @Author: colinjxc
// @Date: 2022-01-25T11:57:31+08:00
// @URL: https://leetcode-cn.com/problems/daily-temperatures


func dailyTemperatures(temperatures []int) []int {
    res := make([]int, len(temperatures))
    stack := []int{}

    for i, t := range temperatures {
        for len(stack) > 0 {
            top := stack[len(stack)-1]
            if t > temperatures[top] {
                res[top] = i - top
                stack = stack[:len(stack)-1]
            } else {
                break;
            }
        }
        stack = append(stack, i)
    }

    for _, leftIndex := range stack {
        res[leftIndex] = 0
    }

    return res
}
