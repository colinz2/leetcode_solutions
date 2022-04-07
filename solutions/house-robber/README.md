
# [](https://leetcode-cn.com/problems/house-robber)

## 题目描述



## 题解

### golang [🔗](house-robber.go) 
```golang
func rob(nums []int) int {
    pre := 0
    curr := 0
    for _, n := range nums {
        tmp := max(curr, pre + n)
        pre, curr = curr, tmp
    }
    return curr
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```
### cpp [🔗](house-robber.cpp) 
```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int cnt = nums.size();
        vector<int> r(cnt, 0);

        if (cnt == 1) return nums[0];

        r[0] = nums[0];
        r[1] = max(nums[0], nums[1]);

        for (int i = 2; i < cnt; i++) {
            r[i] = max(r[i-1], r[i-2]+nums[i]);
        }

        return r[cnt - 1];
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../tenth-line/README.md) 
- [Next](../binary-tree-right-side-view/README.md) 

