
# [按奇偶排序数组](https://leetcode-cn.com/problems/sort-array-by-parity)

## 题目描述

<p>给定一个非负整数数组 <code>A</code>，返回一个数组，在该数组中，&nbsp;<code>A</code> 的所有偶数元素之后跟着所有奇数元素。</p>

<p>你可以返回满足此条件的任何数组作为答案。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>[3,1,2,4]
<strong>输出：</strong>[2,4,3,1]
输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 5000</code></li>
	<li><code>0 &lt;= A[i] &lt;= 5000</code></li>
</ol>


## 题解

### python3 [🔗](sort-array-by-parity.py) 
```python3
class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        j = 0
        for i in range(len(nums)):
            if nums[i] % 2 == 0:
                nums[i], nums[j] = nums[j], nums[i]
                j += 1
        return nums
```
### cpp [🔗](sort-array-by-parity.cpp) 
```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                swap(nums[i], nums[j++]);
            }
        }
        return nums;
    }
};
```
### java [🔗](sort-array-by-parity.java) 
```java
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int i = 0, j = A.length - 1;
        while (i < j) {
            if (A[i] % 2 > A[j] % 2) {
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }

            if (A[i] % 2 == 0) i++;
            if (A[j] % 2 == 1) j--;
        }

        return A;
    }
}

```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 
- [双指针](https://leetcode-cn.com/tag/two-pointers) 
- [排序](https://leetcode-cn.com/tag/sorting) 


## 相似题目



## Links

- [Prev](../maximum-frequency-stack/README.md) 
- [Next](../reverse-only-letters/README.md) 

