
# [元素计数](https://leetcode-cn.com/problems/count-elements-with-strictly-smaller-and-greater-elements)

## 题目描述

<p>给你一个整数数组 <code>nums</code> ，统计并返回在 <code>nums</code> 中同时至少具有一个严格较小元素和一个严格较大元素的元素数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [11,7,2,15]
<strong>输出：</strong>2
<strong>解释：</strong>元素 7 ：严格较小元素是元素 2 ，严格较大元素是元素 11 。
元素 11 ：严格较小元素是元素 7 ，严格较大元素是元素 15 。
总计有 2 个元素都满足在 nums 中同时存在一个严格较小元素和一个严格较大元素。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [-3,3,3,90]
<strong>输出：</strong>2
<strong>解释：</strong>元素 3 ：严格较小元素是元素 -3 ，严格较大元素是元素 90 。
由于有两个元素的值为 3 ，总计有 2 个元素都满足在 nums 中同时存在一个严格较小元素和一个严格较大元素。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


## 题解

### cpp [🔗](count-elements-with-strictly-smaller-and-greater-elements.cpp) 
```cpp
class Solution {
public:
    int countElements(vector<int>& nums) {
        if (nums.size() < 3) {
            return 0;
        }

        std::sort(nums.begin(), nums.end());
        // the range is  [i, j)
        int i = 0, j = nums.size();

        while (i+2 < j && nums[i] == nums[i+1]) i++;
        while (j > i+2 && nums[j-1] == nums[j-2]) j--;
        
        return j - i - 2;
    }
};
```


## 相关话题

- [数组](../../tags/array.md) 
- [排序](../../tags/sorting.md) 


## 相似题目



## Links

- [Prev](../maximum-twin-sum-of-a-linked-list/README.md) 
- [Next](../guess-numbers/README.md) 

