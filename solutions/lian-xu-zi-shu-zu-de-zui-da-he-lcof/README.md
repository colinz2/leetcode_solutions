
# [连续子数组的最大和](https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof)

## 题目描述

<p>输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。</p>

<p>要求时间复杂度为O(n)。</p>

<p>&nbsp;</p>

<p><strong>示例1:</strong></p>

<pre><strong>输入:</strong> nums = [-2,1,-3,4,-1,2,1,-5,4]
<strong>输出:</strong> 6
<strong>解释:</strong>&nbsp;连续子数组&nbsp;[4,-1,2,1] 的和最大，为&nbsp;6。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;arr.length &lt;= 10^5</code></li>
	<li><code>-100 &lt;= arr[i] &lt;= 100</code></li>
</ul>

<p>注意：本题与主站 53 题相同：<a href="https://leetcode-cn.com/problems/maximum-subarray/">https://leetcode-cn.com/problems/maximum-subarray/</a></p>

<p>&nbsp;</p>


## 题解

### cpp [🔗](lian-xu-zi-shu-zu-de-zui-da-he-lcof.cpp) 
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0], sum = 0;
        for (auto num : nums) {
            if (sum < 0) {
                sum = num;
            } else {
                sum += num;
            }
            max_sum = std::max(max_sum, sum);
        }
        return max_sum;
    }
};
```


## 相关话题

- [数组](../../tags/array.md) 
- [分治](../../tags/divide-and-conquer.md) 
- [动态规划](../../tags/dynamic-programming.md) 


## 相似题目



## Links

- [Prev](../zui-xiao-de-kge-shu-lcof/README.md) 
- [Next](../que-shi-de-shu-zi-lcof/README.md) 

