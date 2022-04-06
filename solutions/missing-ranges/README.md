
# [缺失的区间](https://leetcode-cn.com/problems/missing-ranges)

## 题目描述

<p>给定一个排序的整数数组 <em><strong>nums&nbsp;</strong></em>，其中元素的范围在&nbsp;<strong>闭区间</strong>&nbsp;<strong>[<em>lower, upper</em>]</strong>&nbsp;当中，返回不包含在数组中的缺失区间。</p>

<p><strong>示例：</strong></p>

<pre><strong>输入: </strong><strong><em>nums</em></strong> = <code>[0, 1, 3, 50, 75]</code>, <strong><em>lower</em></strong> = 0 和 <strong><em>upper</em></strong> = 99,
<strong>输出: </strong><code>[&quot;2&quot;, &quot;4-&gt;49&quot;, &quot;51-&gt;74&quot;, &quot;76-&gt;99&quot;]</code>
</pre>


## 题解

### cpp [🔗](missing-ranges.cpp) 
```cpp
class Solution
{
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        int L = lower;
        vector<string> res;
        for (int i = 0; i < n; i ++) {
            if (L == nums[i]) {
                L ++;
            } else {
                if (L < nums[i] - 1) {
                    res.push_back(to_string(L) + "->" + to_string(nums[i] - 1));
                } else if (L == nums[i] - 1) {
                    res.push_back(to_string(L));
                }

                L = nums[i] + 1;
            }
        }
        if (L < upper)
            res.push_back(to_string(L) + "->" + to_string(upper));
        if (L == upper)
            res.push_back(to_string(L));        
        return res;
    }
};

```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 


## 相似题目

- [汇总区间](../summary-ranges/README.md)  [Easy] 


## Links

- [Prev](../find-peak-element/README.md) 
- [Next](../two-sum-ii-input-array-is-sorted/README.md) 

