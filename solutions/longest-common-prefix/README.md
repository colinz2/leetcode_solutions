
# [最长公共前缀](https://leetcode-cn.com/problems/longest-common-prefix)

## 题目描述

<p>编写一个函数来查找字符串数组中的最长公共前缀。</p>

<p>如果不存在公共前缀，返回空字符串&nbsp;<code>""</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>strs = ["flower","flow","flight"]
<strong>输出：</strong>"fl"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>strs = ["dog","racecar","car"]
<strong>输出：</strong>""
<strong>解释：</strong>输入不存在公共前缀。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= strs.length &lt;= 200</code></li>
	<li><code>0 &lt;= strs[i].length &lt;= 200</code></li>
	<li><code>strs[i]</code> 仅由小写英文字母组成</li>
</ul>


## 题解

### cpp [🔗](longest-common-prefix.cpp) 
```cpp
class Solution {
public:
    string CommonPrefix(string& a, string& b) {
        //string cp;
        int j = 0;
        for (j = 0; j < a.size() && j < b.size(); j++) {
            if (a[j] == b[j]) {
                //cp.append(1, a[j]);
            } else {
                break;
            }
        }
        //return cp;
        return a.substr(0, j);
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        string lcp = strs[0];
        for (auto i = 0; i < strs.size() - 1; i++) {
            string cp = CommonPrefix(strs[i], strs[i+1]);
            if (cp.size() == 0) {
                return "";
            }
            if (cp.size() < lcp.size()) {
                lcp = cp;
            }
        }
        return  lcp;
    }
};
```


## 相关话题

- [字符串](../../tags/string.md) 


## 相似题目



## Links

- [Prev](../roman-to-integer/README.md) 
- [Next](../3sum/README.md) 

