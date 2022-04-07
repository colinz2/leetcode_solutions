
# [](https://leetcode-cn.com/problems/kill-process)

## 题目描述



## 题解

### golang [🔗](kill-process.go) 
```golang
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
```
### cpp [🔗](kill-process.cpp) 
```cpp
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> res;
        unordered_map<int, vector<int>> children_map;
        for (int i = 0; i < pid.size(); i++) {
            int _pid = pid[i];
            int _ppid = ppid[i];
            children_map[_ppid].push_back(_pid);
        }

        dfsKill(kill, children_map, res);
        return res;
    }

    void dfsKill(int kill, unordered_map<int, vector<int>>& cmap, vector<int>& res) {
        res.push_back(kill);
        vector<int>& children_pid = cmap[kill];
        for (auto& cpid : children_pid) {
            dfsKill(cpid, cmap, res);
        }
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../distribute-candies/README.md) 
- [Next](../delete-operation-for-two-strings/README.md) 

