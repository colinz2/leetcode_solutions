
# [删除有序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array)

## 题目描述

<p>给你一个 <strong>升序排列</strong> 的数组 <code>nums</code> ，请你<strong><a href="http://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95" target="_blank"> 原地</a></strong> 删除重复出现的元素，使每个元素 <strong>只出现一次</strong> ，返回删除后数组的新长度。元素的 <strong>相对顺序</strong> 应该保持 <strong>一致</strong> 。</p>

<p>由于在某些语言中不能改变数组的长度，所以必须将结果放在数组nums的第一部分。更规范地说，如果在删除重复项之后有 <code>k</code> 个元素，那么&nbsp;<code>nums</code>&nbsp;的前 <code>k</code> 个元素应该保存最终结果。</p>

<p>将最终结果插入&nbsp;<code>nums</code> 的前 <code>k</code> 个位置后返回 <code>k</code> 。</p>

<p>不要使用额外的空间，你必须在 <strong><a href="https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95" target="_blank">原地 </a>修改输入数组 </strong>并在使用 O(1) 额外空间的条件下完成。</p>

<p><strong>判题标准:</strong></p>

<p>系统会用下面的代码来测试你的题解:</p>

<pre>
int[] nums = [...]; // 输入数组
int[] expectedNums = [...]; // 长度正确的期望答案

int k = removeDuplicates(nums); // 调用

assert k == expectedNums.length;
for (int i = 0; i &lt; k; i++) {
    assert nums[i] == expectedNums[i];
}</pre>

<p>如果所有断言都通过，那么您的题解将被 <strong>通过</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,2]
<strong>输出：</strong>2, nums = [1,2,_]
<strong>解释：</strong>函数应该返回新的长度 <strong><code>2</code></strong> ，并且原数组 <em>nums </em>的前两个元素被修改为 <strong><code>1</code></strong>, <strong><code>2 </code></strong><code>。</code>不需要考虑数组中超出新长度后面的元素。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,0,1,1,1,2,2,3,3,4]
<strong>输出：</strong>5, nums = [0,1,2,3,4]
<strong>解释：</strong>函数应该返回新的长度 <strong><code>5</code></strong> ， 并且原数组 <em>nums </em>的前五个元素被修改为 <strong><code>0</code></strong>, <strong><code>1</code></strong>, <strong><code>2</code></strong>, <strong><code>3</code></strong>, <strong><code>4</code></strong> 。不需要考虑数组中超出新长度后面的元素。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code> 已按 <strong>升序</strong> 排列</li>
</ul>


## 题解

### cpp [🔗](remove-duplicates-from-sorted-array.cpp) 
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        if (nums.size() == 0) {
            return 0;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums[j - 1]) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};

```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 
- [双指针](https://leetcode-cn.com/tag/two-pointers) 


## 相似题目

- [移除元素](../remove-element/README.md)  [Easy] 
- [删除有序数组中的重复项 II](../remove-duplicates-from-sorted-array-ii/README.md)  [Medium] 


## Links

- [Prev](../reverse-nodes-in-k-group/README.md) 
- [Next](../remove-element/README.md) 

