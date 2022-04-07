
# [跳跃游戏](https://leetcode-cn.com/problems/jump-game)

## 题目描述

<p>给定一个非负整数数组 <code>nums</code> ，你最初位于数组的 <strong>第一个下标</strong> 。</p>

<p>数组中的每个元素代表你在该位置可以跳跃的最大长度。</p>

<p>判断你是否能够到达最后一个下标。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,3,1,1,4]
<strong>输出：</strong>true
<strong>解释：</strong>可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,2,1,0,4]
<strong>输出：</strong>false
<strong>解释：</strong>无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 3 * 10<sup>4</sup></code></li>
	<li><code>0 <= nums[i] <= 10<sup>5</sup></code></li>
</ul>


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

- [贪心](../../tags/greedy.md) 
- [数组](../../tags/array.md) 
- [动态规划](../../tags/dynamic-programming.md) 


## 相似题目



## Links

- [Prev](../spiral-matrix/README.md) 
- [Next](../merge-intervals/README.md) 

