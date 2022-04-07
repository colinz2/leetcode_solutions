
# [只出现一次的数字](https://leetcode-cn.com/problems/single-number)

## 题目描述

<p>给定一个<strong>非空</strong>整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。</p>

<p><strong>说明：</strong></p>

<p>你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [2,2,1]
<strong>输出:</strong> 1
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> [4,1,2,1,2]
<strong>输出:</strong> 4</pre>


## 题解

### cpp [🔗](single-number.cpp) 
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int yh = 0;
        int i = 0;
        for (; i + 3 < nums.size(); i += 4) {
            yh ^= nums[i];
            yh ^= nums[i+1];
            yh ^= nums[i+2];
            yh ^= nums[i+3];
        }

        for (; i < nums.size(); i++) {
            yh ^= nums[i];
        }
        return yh;
    }
};
```


## 相关话题

- [位运算](../../tags/bit-manipulation.md) 
- [数组](../../tags/array.md) 


## 相似题目

- [丢失的数字](../missing-number/README.md)  [Easy] 
- [找不同](../find-the-difference/README.md)  [Easy] 


## Links

- [Prev](../surrounded-regions/README.md) 
- [Next](../copy-list-with-random-pointer/README.md) 

