
# [最大数](https://leetcode-cn.com/problems/largest-number)

## 题目描述

<p>给定一组非负整数 <code>nums</code>，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。</p>

<p><strong>注意：</strong>输出结果可能非常大，所以你需要返回一个字符串而不是整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入<code>：</code></strong><code>nums = [10,2]</code>
<strong>输出：</strong><code>"210"</code></pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入<code>：</code></strong><code>nums = [3,30,34,5,9]</code>
<strong>输出：</strong><code>"9534330"</code>
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


## 题解

### cpp [🔗](largest-number.cpp) 
```cpp
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](int a, int b) {
            string sa = std::to_string(a), sb = std::to_string(b);
            return sa + sb > sb + sa;
        });

        if (nums[0] == 0) return "0";
        
        std::string res;
        for (auto n : nums) {
            res += std::to_string(n);
        }
        return res;
    }
};
```


## 相关话题

- [贪心](https://leetcode-cn.com/tag/greedy) 
- [字符串](https://leetcode-cn.com/tag/string) 
- [排序](https://leetcode-cn.com/tag/sorting) 


## 相似题目



## Links

- [Prev](../second-highest-salary/README.md) 
- [Next](../rotate-array/README.md) 

