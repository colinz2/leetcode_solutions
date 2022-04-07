
# [](https://leetcode-cn.com/problems/jump-game)

## 题目描述



## 题解

### cpp [🔗](jump-game.cpp) 
```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far_most = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (far_most < i) 
                return false;
            if (nums[i] + i > far_most) {
                far_most = nums[i] + i;
            }
            if (far_most >= nums.size() - 1)
                return true;
        }
        return far_most >= nums.size() - 1;
    }
};
```
### python3 [🔗](jump-game.py) 
```python3
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n, far_most = len(nums), 0
        for i in range(n):
            if i <= far_most:
                far_most = max(far_most, i + nums[i])
                if far_most + 1 >= len(nums):
                    return True
            else:
                break
        return False
```


## 相关话题



## 相似题目



## Links

- [Prev](../spiral-matrix/README.md) 
- [Next](../merge-intervals/README.md) 

