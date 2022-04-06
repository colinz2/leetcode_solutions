
# [可被 5 整除的二进制前缀](https://leetcode-cn.com/problems/binary-prefix-divisible-by-5)

## 题目描述

<p>给定一个二进制数组 <code>nums</code> (&nbsp;<strong>索引从0开始&nbsp;</strong>)。</p>

<p>我们将<code>x<sub>i</sub></code>&nbsp;定义为其二进制表示形式为子数组&nbsp;<code>nums[0..i]</code>&nbsp;(从最高有效位到最低有效位)。</p>

<ul>
	<li>例如，如果 <code>nums =[1,0,1]</code> ，那么&nbsp;<code>x<sub>0</sub>&nbsp;= 1</code>,&nbsp;<code>x<sub>1</sub>&nbsp;= 2</code>, 和&nbsp;<code>x<sub>2</sub>&nbsp;= 5</code>。</li>
</ul>

<p>返回布尔值列表&nbsp;<code>answer</code>，只有当&nbsp;<code>x<sub>i</sub></code><em>&nbsp;</em>可以被 <code>5</code>&nbsp;整除时，答案&nbsp;<code>answer[i]</code> 为&nbsp;<code>true</code>，否则为 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,1,1]
<strong>输出：</strong>[true,false,false]
<strong>解释：</strong>
输入数字为 0, 01, 011；也就是十进制中的 0, 1, 3 。只有第一个数可以被 5 整除，因此 answer[0] 为 true 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1]
<strong>输出：</strong>[false,false,false]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code><sup>&nbsp;</sup></li>
	<li><code>nums[i]</code>&nbsp;仅为&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code></li>
</ul>


## 题解

### cpp [🔗](binary-prefix-divisible-by-5.cpp) 
```cpp
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int size = nums.size();
        vector<bool> res(size, false);
        int num = 0;
        for (int i = 0; i < size; i++) {
            num = (num << 1) + nums[i];
            num = num % 5;
            res[i] = (num == 0);
        }
        return res;
    }
};
```
### golang [🔗](binary-prefix-divisible-by-5.go) 
```golang
func prefixesDivBy5(nums []int) []bool {
    ans := make([]bool, len(nums))
    x := 0
    // 如果x为和而不取模，有溢出问题啊！！！
    for i, v := range nums {
        x = (x<<1 | v) % 5
        ans[i] = x == 0
    }
    return ans
}
```
### java [🔗](binary-prefix-divisible-by-5.java) 
```java
class Solution {
    // 有限状态机 DFA ？
    public List<Boolean> prefixesDivBy5(int[] nums) {
        List<Boolean> res = new ArrayList<>();
        if (nums.length < 1) {
            return res;
        }
        int StateSet[][] = new int[][]{
                {0, 1},
                {2, 3},
                {4, 0},
                {1, 2},
                {3, 4}
        };
        int state = 0;
        for (int i = 0; i < nums.length; i++) {
            state = StateSet[state][nums[i]];  //转换后的状态
            if (state == 0) {
                res.add(Boolean.TRUE);
            } else {
                res.add(Boolean.FALSE);
            }
        }
        return res;
    }
}
```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 


## 相似题目



## Links

- [Prev](../fixed-point/README.md) 
- [Next](../number-of-enclaves/README.md) 

