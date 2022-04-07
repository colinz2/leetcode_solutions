
# [移动零](https://leetcode-cn.com/problems/move-zeroes)

## 题目描述

<p>给定一个数组 <code>nums</code>，编写一个函数将所有 <code>0</code> 移动到数组的末尾，同时保持非零元素的相对顺序。</p>

<p><strong>请注意</strong>&nbsp;，必须在不复制数组的情况下原地对数组进行操作。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = <code>[0,1,0,3,12]</code>
<strong>输出:</strong> <code>[1,3,12,0,0]</code>
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = <code>[0]</code>
<strong>输出:</strong> <code>[0]</code></pre>

<p>&nbsp;</p>

<p><strong>提示</strong>:</p>
<meta charset="UTF-8" />

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-2<sup>31</sup>&nbsp;&lt;= nums[i] &lt;= 2<sup>31</sup>&nbsp;- 1</code></li>
</ul>

<p>&nbsp;</p>

<p><b>进阶：</b>你能尽量减少完成的操作次数吗？</p>


## 题解

### cpp [🔗](move-zeroes.cpp) 
```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                if (j != k) {
                    std::swap(nums[k], nums[j]);   
                }
                k++;
            }
        }
    }
};
```
### golang [🔗](move-zeroes.go) 
```golang
func moveZeroes(nums []int) {
	k := 0
	for i := range nums {
		if nums[i] != 0 {
			if i != k {
				nums[i], nums[k] = nums[k], nums[i]
			}
			k++
		}
	}
}
```


## 相关话题

- [数组](../../tags/array.md) 
- [双指针](../../tags/two-pointers.md) 


## 相似题目

- [移除元素](../remove-element/README.md)  [Easy] 


## Links

- [Prev](../perfect-squares/README.md) 
- [Next](../game-of-life/README.md) 

