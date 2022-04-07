
# [数组中重复的数字](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof)

## 题目描述

<p>找出数组中重复的数字。</p>

<p><br>
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>
[2, 3, 1, 0, 2, 5, 3]
<strong>输出：</strong>2 或 3 
</pre>

<p>&nbsp;</p>

<p><strong>限制：</strong></p>

<p><code>2 &lt;= n &lt;= 100000</code></p>


## 题解

### cpp [🔗](shu-zu-zhong-zhong-fu-de-shu-zi-lcof.cpp) 
```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        auto len = nums.size();
        for (auto i = 0; i < len; i++) {
            auto idx = nums[i] % len;
            if (nums[idx] >= len ) {
                return idx;
            }
            nums[idx] += len;
        }
        return -1;
    }
};
```
### golang [🔗](shu-zu-zhong-zhong-fu-de-shu-zi-lcof.go) 
```golang
func findRepeatNumber(nums []int) int {
    seen := make(map[int]struct{})
    for _, n := range nums {
        if _, e := seen[n]; e {
            return n
        }
        seen[n] = struct{}{}
    }
    return -1
}
```
### python3 [🔗](shu-zu-zhong-zhong-fu-de-shu-zi-lcof.py) 
```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        seen = set()
        for n in nums:
            if n in seen:
                return n
            seen.add(n)
        return -1
```
### c [🔗](shu-zu-zhong-zhong-fu-de-shu-zi-lcof.c) 
```c
int findRepeatNumber(int* nums, int numsSize){
    for (int i = 0; i < numsSize; i++) {
        int idx = nums[i] % numsSize;
        if (nums[idx] >= numsSize) {
            return idx;
        }
        nums[idx] += numsSize;
    }
    return -1;
}
```


## 相关话题

- [数组](../../tags/array.md) 
- [哈希表](../../tags/hash-table.md) 
- [排序](../../tags/sorting.md) 


## 相似题目



## Links

- [Prev](../fei-bo-na-qi-shu-lie-lcof/README.md) 
- [Next](../xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/README.md) 

