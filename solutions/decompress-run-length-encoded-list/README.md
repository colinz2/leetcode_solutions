
# [解压缩编码列表](https://leetcode-cn.com/problems/decompress-run-length-encoded-list)

## 题目描述

<p>给你一个以行程长度编码压缩的整数列表 <code>nums</code> 。</p>

<p>考虑每对相邻的两个元素 <code>[freq, val] = [nums[2*i], nums[2*i+1]]</code> （其中 <code>i >= 0</code> ），每一对都表示解压后子列表中有 <code>freq</code> 个值为 <code>val</code> 的元素，你需要从左到右连接所有子列表以生成解压后的列表。</p>

<p>请你返回解压后的列表。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4]
<strong>输出：</strong>[2,4,4,4]
<strong>解释：</strong>第一对 [1,2] 代表着 2 的出现频次为 1，所以生成数组 [2]。
第二对 [3,4] 代表着 4 的出现频次为 3，所以生成数组 [4,4,4]。
最后将它们串联到一起 [2] + [4,4,4] = [2,4,4,4]。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,2,3]
<strong>输出：</strong>[1,3,3]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= nums.length <= 100</code></li>
	<li><code>nums.length % 2 == 0</code></li>
	<li><code>1 <= nums[i] <= 100</code></li>
</ul>


## 题解

### cpp [🔗](decompress-run-length-encoded-list.cpp) 
```cpp
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i += 2) {
            int freq = nums[i];
            for (int j = 0; j < freq; j++) {
                res.push_back(nums[i+1]);
            }
        }
        return res;
    }
};
```


## 相关话题

- [数组](../../tags/array.md) 


## 相似题目



## Links

- [Prev](../n-th-tribonacci-number/README.md) 
- [Next](../longest-common-subsequence/README.md) 

