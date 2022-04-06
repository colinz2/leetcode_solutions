
# [三数之和](https://leetcode-cn.com/problems/3sum)

## 题目描述

<p>给你一个包含 <code>n</code> 个整数的数组 <code>nums</code>，判断 <code>nums</code> 中是否存在三个元素 <em>a，b，c ，</em>使得 <em>a + b + c = </em>0 ？请你找出所有和为 <code>0</code> 且不重复的三元组。</p>

<p><strong>注意：</strong>答案中不可以包含重复的三元组。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,0,1,2,-1,-4]
<strong>输出：</strong>[[-1,-1,2],[-1,0,1]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = []
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [0]
<strong>输出：</strong>[]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= nums.length <= 3000</code></li>
	<li><code>-10<sup>5</sup> <= nums[i] <= 10<sup>5</sup></code></li>
</ul>


## 题解

### cpp [🔗](3sum.cpp) 
```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        if (nums.size() == 0) return ret;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            int target = -nums[i];
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    ret.push_back({nums[i], nums[l], nums[r]});
                    //哈哈\U0001f604
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                } else if (nums[l] + nums[r] > target) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ret;
    }
};
```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 
- [双指针](https://leetcode-cn.com/tag/two-pointers) 
- [排序](https://leetcode-cn.com/tag/sorting) 


## 相似题目

- [两数之和](../two-sum/README.md)  [Easy] 


## Links

- [Prev](../longest-common-prefix/README.md) 
- [Next](../letter-combinations-of-a-phone-number/README.md) 

