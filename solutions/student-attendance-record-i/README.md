
# [学生出勤记录 I](https://leetcode-cn.com/problems/student-attendance-record-i)

## 题目描述

<p>给你一个字符串 <code>s</code> 表示一个学生的出勤记录，其中的每个字符用来标记当天的出勤情况（缺勤、迟到、到场）。记录中只含下面三种字符：</p>

<ul>
	<li><code>'A'</code>：Absent，缺勤</li>
	<li><code>'L'</code>：Late，迟到</li>
	<li><code>'P'</code>：Present，到场</li>
</ul>

<p>如果学生能够 <strong>同时</strong> 满足下面两个条件，则可以获得出勤奖励：</p>

<ul>
	<li>按 <strong>总出勤</strong> 计，学生缺勤（<code>'A'</code>）<strong>严格</strong> 少于两天。</li>
	<li>学生 <strong>不会</strong> 存在 <strong>连续</strong> 3 天或 <strong>连续</strong> 3 天以上的迟到（<code>'L'</code>）记录。</li>
</ul>

<p>如果学生可以获得出勤奖励，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "PPALLP"
<strong>输出：</strong>true
<strong>解释：</strong>学生缺勤次数少于 2 次，且不存在 3 天或以上的连续迟到记录。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "PPALLL"
<strong>输出：</strong>false
<strong>解释：</strong>学生最后三天连续迟到，所以不满足出勤奖励的条件。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code> 为 <code>'A'</code>、<code>'L'</code> 或 <code>'P'</code></li>
</ul>


## 题解

### cpp [🔗](student-attendance-record-i.cpp) 
```cpp
class Solution {
public:
    bool checkRecord(string s) {
        int record[256] = {0, };

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            record[c] += 1;
            if (c == 'L') {
                if (record[c] > 2) return false;
                if (c != s[i + 1]) record[c] = 0;
            } else if (c == 'A') {
                if (record[c] > 1) return false;
            }
        }
        return true;
    }
};
```
### golang [🔗](student-attendance-record-i.go) 
```golang
func checkRecord(s string) bool {
    l, a := 0, 0
    for i := 0; i < len(s); i++ {
        if (s[i] == 'L') {
            l += 1
        } else if (s[i] == 'A') {
            l = 0;
            a += 1
        } else {
            l = 0;
        }
        
        if l > 2 || a > 1 {
            return false
        }
    }
    return true
}
```


## 相关话题

- [字符串](../../tags/string.md) 


## 相似题目



## Links

- [Prev](../number-of-provinces/README.md) 
- [Next](../reverse-words-in-a-string-iii/README.md) 

