
# [最富有客户的资产总量](https://leetcode-cn.com/problems/richest-customer-wealth)

## 题目描述

<p>给你一个 <code>m x n</code> 的整数网格 <code>accounts</code> ，其中 <code>accounts[i][j]</code> 是第 <code>i​​​​​<sup>​​​​​​</sup>​</code> 位客户在第 <code>j</code> 家银行托管的资产数量。返回最富有客户所拥有的 <strong>资产总量</strong> 。</p>

<p>客户的 <strong>资产总量</strong> 就是他们在各家银行托管的资产数量之和。最富有客户就是 <strong>资产总量</strong> 最大的客户。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>accounts = [[1,2,3],[3,2,1]]
<strong>输出：</strong>6
<strong>解释：</strong>
<code>第 1 位客户的资产总量 = 1 + 2 + 3 = 6
第 2 位客户的资产总量 = 3 + 2 + 1 = 6
</code>两位客户都是最富有的，资产总量都是 6 ，所以返回 6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>accounts = [[1,5],[7,3],[3,5]]
<strong>输出：</strong>10
<strong>解释：</strong>
<code>第 1 位客户的资产总量</code> = 6
<code>第 2 位客户的资产总量</code> = 10 
<code>第 3 位客户的资产总量</code> = 8
第 2 位客户是最富有的，资产总量是 10</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>accounts = [[2,8,7],[7,1,3],[1,9,5]]
<strong>输出：</strong>17
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == accounts.length</code></li>
	<li><code>n == accounts[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>1 &lt;= accounts[i][j] &lt;= 100</code></li>
</ul>


## 题解

### c [🔗](richest-customer-wealth.c) 
```c
int maximumWealth(int** accounts, int accountsSize, int* accountsColSize){
    int maxW = 0;
    for (int i = 0; i < accountsSize; i++) {
        int wealthOneAccount = 0;
        for (int j = 0; j < accountsColSize[i]; j++) {
            wealthOneAccount += accounts[i][j];
        }
        if (maxW < wealthOneAccount) {
            maxW = wealthOneAccount;
        } 
    }
    return maxW;
}
```
### cpp [🔗](richest-customer-wealth.cpp) 
```cpp
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        vector<int> res;
        for (auto &v : accounts) {
            res.push_back(accumulate(v.begin(), v.end(), 0));
        }
        sort(res.begin(), res.end());
        return res.back();
    }
};
```
### golang [🔗](richest-customer-wealth.go) 
```golang
func maximumWealth(accounts [][]int) int {
    // 原地操作
    for i := 0; i < len(accounts); i++ {
        for j := 1; j < len(accounts[0]); j++ {
            accounts[i][0] += accounts[i][j]
        }
        if accounts[0][0] < accounts[i][0] {
            accounts[0][0] = accounts[i][0]
        }
    }
    return accounts[0][0]
}
```
### python [🔗](richest-customer-wealth.py) 
```python
class Solution(object):
    def maximumWealth(self, accounts):
        """
        :type accounts: List[List[int]]
        :rtype: int
        """
        return max([sum(account) for account in accounts])
```
### rust [🔗](richest-customer-wealth.rs) 
```rust
impl Solution {
    pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
        accounts.iter()
            .map(|v|v.iter().sum())
            .max()
            .unwrap()
    }
}
```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 
- [矩阵](https://leetcode-cn.com/tag/matrix) 


## 相似题目



## Links

- [Prev](../merge-in-between-linked-lists/README.md) 
- [Next](../delete-the-middle-node-of-a-linked-list/README.md) 

