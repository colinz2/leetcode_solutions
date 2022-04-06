
# [两个数组的交集 II](https://leetcode-cn.com/problems/intersection-of-two-arrays-ii)

## 题目描述

<p>给你两个整数数组&nbsp;<code>nums1</code> 和 <code>nums2</code> ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1,2,2,1], nums2 = [2,2]
<strong>输出：</strong>[2,2]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入：</strong>nums1 = [4,9,5], nums2 = [9,4,9,8,4]
<strong>输出：</strong>[4,9]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>

<p><strong><strong>进阶</strong>：</strong></p>

<ul>
	<li>如果给定的数组已经排好序呢？你将如何优化你的算法？</li>
	<li>如果&nbsp;<code>nums1</code><em>&nbsp;</em>的大小比&nbsp;<code>nums2</code> 小，哪种方法更优？</li>
	<li>如果&nbsp;<code>nums2</code><em>&nbsp;</em>的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？</li>
</ul>


## 题解

### cpp [🔗](intersection-of-two-arrays-ii.cpp) 
```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        multiset<int> record;
        for(int num: nums1)
            record.insert(num);

        multiset<int> result;
        for(int num: nums2){
            multiset<int>::iterator iter = record.find(num);
            if( iter != record.end()){
                result.insert(num);
                record.erase(iter);
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};
```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 
- [哈希表](https://leetcode-cn.com/tag/hash-table) 
- [双指针](https://leetcode-cn.com/tag/two-pointers) 
- [二分查找](https://leetcode-cn.com/tag/binary-search) 
- [排序](https://leetcode-cn.com/tag/sorting) 


## 相似题目

- [两个数组的交集](../intersection-of-two-arrays/README.md)  [Easy] 


## Links

- [Prev](../intersection-of-two-arrays/README.md) 
- [Next](../design-twitter/README.md) 

