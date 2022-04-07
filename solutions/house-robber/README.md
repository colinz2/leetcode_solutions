
# [打家劫舍](https://leetcode-cn.com/problems/house-robber)

## 题目描述

<p>你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，<strong>如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警</strong>。</p>

<p>给定一个代表每个房屋存放金额的非负整数数组，计算你<strong> 不触动警报装置的情况下 </strong>，一夜之内能够偷窃到的最高金额。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>[1,2,3,1]
<strong>输出：</strong>4
<strong>解释：</strong>偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>[2,7,9,3,1]
<strong>输出：</strong>12
<strong>解释：</strong>偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 100</code></li>
	<li><code>0 <= nums[i] <= 400</code></li>
</ul>


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

- [数组](../../tags/array.md) 
- [动态规划](../../tags/dynamic-programming.md) 


## 相似题目

- [打家劫舍 II](../house-robber-ii/README.md)  [Medium] 
- [打家劫舍 III](../house-robber-iii/README.md)  [Medium] 


## Links

- [Prev](../tenth-line/README.md) 
- [Next](../binary-tree-right-side-view/README.md) 

