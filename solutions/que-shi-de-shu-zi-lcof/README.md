
# [0～n-1中缺失的数字](https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof)

## 题目描述

<p>一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [0,1,3]
<strong>输出:</strong> 2
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> [0,1,2,3,4,5,6,7,9]
<strong>输出:</strong> 8</pre>

<p>&nbsp;</p>

<p><strong>限制：</strong></p>

<p><code>1 &lt;= 数组长度 &lt;= 10000</code></p>


## 题解

### c [🔗](que-shi-de-shu-zi-lcof.c) 
```c
int missingNumber(int* nums, int numsSize){
    int i = 0; 
    for (; i < numsSize; i++) {
        if (nums[i] != i) {
            return i;
        }
    }
    return i;
}
```
### cpp [🔗](que-shi-de-shu-zi-lcof.cpp) 
```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = (lo + hi) /2;
            if (nums[mid] == mid) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return hi;
    }
};
```


## 相关话题

- [位运算](../../tags/bit-manipulation.md) 
- [数组](../../tags/array.md) 
- [哈希表](../../tags/hash-table.md) 
- [数学](../../tags/math.md) 
- [二分查找](../../tags/binary-search.md) 


## 相似题目



## Links

- [Prev](../lian-xu-zi-shu-zu-de-zui-da-he-lcof/README.md) 
- [Next](../er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/README.md) 

