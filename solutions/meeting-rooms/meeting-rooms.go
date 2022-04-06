// @Title: Meeting Rooms
// @Author: colinjxc
// @Date: 2022-02-08T11:44:38+08:00
// @URL: https://leetcode-cn.com/problems/meeting-rooms


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
