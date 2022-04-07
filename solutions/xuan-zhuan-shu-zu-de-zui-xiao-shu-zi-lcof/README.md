
# [旋转数组的最小数字](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof)

## 题目描述

<p>把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。</p>

<p>给你一个可能存在&nbsp;<strong>重复</strong>&nbsp;元素值的数组&nbsp;<code>numbers</code>&nbsp;，它原来是一个升序排列的数组，并按上述情形进行了一次旋转。请返回旋转数组的<strong>最小元素</strong>。例如，数组&nbsp;<code>[3,4,5,1,2]</code> 为 <code>[1,2,3,4,5]</code> 的一次旋转，该数组的最小值为 1。&nbsp;&nbsp;</p>

<p>注意，数组 <code>[a[0], a[1], a[2], ..., a[n-1]]</code> 旋转一次 的结果为数组 <code>[a[n-1], a[0], a[1], a[2], ..., a[n-2]]</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong><code>numbers = </code>[3,4,5,1,2]
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong><code>numbers = </code>[2,2,2,0,1]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == numbers.length</code></li>
	<li><code>1 &lt;= n &lt;= 5000</code></li>
	<li><code>-5000 &lt;= numbers[i] &lt;= 5000</code></li>
	<li><code>numbers</code> 原来是一个升序排序的数组，并进行了 <code>1</code> 至 <code>n</code> 次旋转</li>
</ul>

<p>注意：本题与主站 154 题相同：<a href="https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/">https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/</a></p>


## 题解

### cpp [🔗](xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof.cpp) 
```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int l = 0, r = numbers.size() - 1;
        if (numbers.size() == 0) return -1;
        // 二分查找
        // 确定 target 为最右端 r
        // [5,1,2,3,4]
        // 如果 num[mid] < num[r], 则 mid右边全部是有序的(可以用反证法证明), 在左侧找，r = mid
        // 如果 num[mid] == num[r], 则 r = r - 1
        // 如果 num[mid] > num[r], 则 可以确定在 mid 右侧找， l = mid + 1

        while (l <= r) {
            int mid = (r-l)/2 + l;
            if (numbers[mid] > numbers[r]) {
                l = mid + 1;
            } else if (numbers[mid] < numbers[r]){
                r = mid;
            } else {
                r = r - 1;
            }
        }

        return numbers[l];
    }
};
```


## 相关话题

- [数组](../../tags/array.md) 
- [二分查找](../../tags/binary-search.md) 


## 相似题目



## Links

- [Prev](../shu-zu-zhong-zhong-fu-de-shu-zi-lcof/README.md) 
- [Next](../ti-huan-kong-ge-lcof/README.md) 

