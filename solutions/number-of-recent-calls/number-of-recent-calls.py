// @Title: Number of Recent Calls
// @Author: colinjxc
// @Date: 2022-01-31T17:32:45+08:00
// @URL: https://leetcode-cn.com/problems/number-of-recent-calls


class RecentCounter:

    def __init__(self):
        from collections import deque
        self.q = deque()

    def ping(self, t: int) -> int:
        self.q.append(t)
        while self.q[0] + 3000 < t:
            self.q.popleft()

        return len(self.q)


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
