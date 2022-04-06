// @Title: Kill Process
// @Author: colinjxc
// @Date: 2022-02-06T19:05:42+08:00
// @URL: https://leetcode-cn.com/problems/kill-process


func killProcess(pid []int, ppid []int, kill int) []int {
    cmap := make(map[int][]int)
    for i, _pid := range pid {
        _ppid := ppid[i]
        cmap[_ppid] = append(cmap[_ppid], _pid)
    }
    res := []int{}
    queue := []int{}
    queue = append(queue, kill)

    for len(queue) > 0 {
        headPid := queue[0]
        queue = queue[1:]
        res = append(res, headPid)
        
        _pids := cmap[headPid]
        for j := 0; j < len(_pids); j++ {
            queue = append(queue, _pids[j])
        }
    }
    return res;
}
