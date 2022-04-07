
# [搜索长度未知的有序数组](https://leetcode-cn.com/problems/search-in-a-sorted-array-of-unknown-size)

## 题目描述

<p>这是一个<strong>交互问题</strong>。</p>

<p>您有一个<strong>升序</strong>整数数组，其<strong>长度未知</strong>。您没有访问数组的权限，但是可以使用&nbsp;<code>ArrayReader&nbsp;</code>接口访问它。你可以调用&nbsp;<code>ArrayReader.get(i)</code>:</p>

<ul>
	<li>
	<p>返回数组第<code>i<sup>th</sup></code>个索引(<strong>0-indexed</strong>)处的值(即<code>secret[i]</code>)，或者</p>
	</li>
	<li>
	<p>如果&nbsp;<code>i</code>&nbsp; 超出了数组的边界，则返回&nbsp;<code>2<sup>31</sup>&nbsp;- 1</code></p>
	</li>
</ul>

<p>你也会得到一个整数 <code>target</code>。</p>

<p>如果存在<code>secret[k] == target</code>，请返回索引&nbsp;<code>k</code>&nbsp;的值；否则返回&nbsp;<code>-1</code></p>

<p>你必须写一个时间复杂度为&nbsp;<code>O(log n)</code>&nbsp;的算法。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> <code>secret</code> = [-1,0,3,5,9,12], <code>target</code> = 9
<strong>输出:</strong> 4
<strong>解释:</strong> 9 存在在 nums 中，下标为 4
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入:</strong> <code>secret</code> = [-1,0,3,5,9,12], <code>target</code> = 2
<strong>输出:</strong> -1
<strong>解释:</strong> 2 不在数组中所以返回 -1</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= secret.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup>&nbsp;&lt;= secret[i], target &lt;= 10<sup>4</sup></code></li>
	<li><code>secret</code>&nbsp;严格递增</li>
</ul>


## 题解

### cpp [🔗](search-in-a-sorted-array-of-unknown-size.cpp) 
```cpp
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int i = 0, j = 10e4;
        while (i < j) {
            int m = i + (j - i)/2;
            if (reader.get(m) == INT_MAX) {
                j = m;
            } else {
                i = m + 1;
            }
        }
        
        j = 0;

        while (j < i) {
            int m = j + (i - i)/2;
            if ((reader.get(m) < target)) {
                j = m + 1;
            } else if ((reader.get(m) > target)) {
                i = m;
            } else {
                return m;
            }
        }
        return -1;
    }
};
```
### c [🔗](search-in-a-sorted-array-of-unknown-size.c) 
```c
/**
 * *********************************************************************
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * int getElement(ArrayReader *, int index);
 */

int search(struct ArrayReader* reader, int target) {
    int i = 0, j = 10e4+1;

    while (i < j) {
        int m = (i+j)>>1;
        int res = getElement(reader, m);
        if (res > target) {
            j = m;
        } else if (res < target) {
            i = m + 1;
        } else {
            return m;
        }
    }

    return -1;    
}
```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 
- [二分查找](https://leetcode-cn.com/tag/binary-search) 
- [交互](https://leetcode-cn.com/tag/interactive) 


## 相似题目

- [二分查找](../binary-search/README.md)  [Easy] 


## Links

- [Prev](../search-in-a-binary-search-tree/README.md) 
- [Next](../kth-largest-element-in-a-stream/README.md) 

