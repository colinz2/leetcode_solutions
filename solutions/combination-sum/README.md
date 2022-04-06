
# [组合总和](https://leetcode-cn.com/problems/combination-sum)

## 题目描述

<p>给你一个 <strong>无重复元素</strong> 的整数数组&nbsp;<code>candidates</code> 和一个目标整数&nbsp;<code>target</code>&nbsp;，找出&nbsp;<code>candidates</code>&nbsp;中可以使数字和为目标数&nbsp;<code>target</code> 的 <em>所有&nbsp;</em><strong>不同组合</strong> ，并以列表形式返回。你可以按 <strong>任意顺序</strong> 返回这些组合。</p>

<p><code>candidates</code> 中的 <strong>同一个</strong> 数字可以 <strong>无限制重复被选取</strong> 。如果至少一个数字的被选数量不同，则两种组合是不同的。&nbsp;</p>

<p>对于给定的输入，保证和为&nbsp;<code>target</code> 的不同组合数少于 <code>150</code> 个。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>candidates = <code>[2,3,6,7], </code>target = <code>7</code>
<strong>输出：</strong>[[2,2,3],[7]]
<strong>解释：</strong>
2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
7 也是一个候选， 7 = 7 。
仅有这两种组合。</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入: </strong>candidates = [2,3,5]<code>, </code>target = 8
<strong>输出: </strong>[[2,2,2,2],[2,3,3],[3,5]]</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入: </strong>candidates = <code>[2], </code>target = 1
<strong>输出: </strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= candidates.length &lt;= 30</code></li>
	<li><code>1 &lt;= candidates[i] &lt;= 200</code></li>
	<li><code>candidate</code> 中的每个元素都 <strong>互不相同</strong></li>
	<li><code>1 &lt;= target &lt;= 500</code></li>
</ul>


## 题解

### cpp [🔗](combination-sum.cpp) 
```cpp
class Solution {
private:
    void combinationSum(vector<int>& candidates, int index, int target, vector<int>& one, vector<vector<int>>& res) {
        for (int i = index; i < candidates.size(); i++) {
            if (target < candidates[i]) {
                break;
            } else if (target == candidates[i]) {
                one.push_back(candidates[i]);
                res.push_back(one);
                one.pop_back();
            } else {
                one.push_back(candidates[i]);
                //target 为i，\U0001f431
                combinationSum(candidates, i, target - candidates[i], one, res);
                one.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> one;
        sort(candidates.begin(), candidates.end());
        combinationSum(candidates, 0, target, one, res);
        return res;
    }
};

```


## 相关话题

- [数组](https://leetcode-cn.com/tag/array) 
- [回溯](https://leetcode-cn.com/tag/backtracking) 


## 相似题目

- [电话号码的字母组合](../letter-combinations-of-a-phone-number/README.md)  [Medium] 
- [组合](../combinations/README.md)  [Medium] 
- [因子的组合](../factor-combinations/README.md)  [Medium] 


## Links

- [Prev](../count-and-say/README.md) 
- [Next](../trapping-rain-water/README.md) 

