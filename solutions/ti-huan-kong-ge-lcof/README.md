
# [替换空格](https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof)

## 题目描述

<p>请实现一个函数，把字符串 <code>s</code> 中的每个空格替换成&quot;%20&quot;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = &quot;We are happy.&quot;
<strong>输出：</strong>&quot;We%20are%20happy.&quot;</pre>

<p>&nbsp;</p>

<p><strong>限制：</strong></p>

<p><code>0 &lt;= s 的长度 &lt;= 10000</code></p>


## 题解

### cpp [🔗](ti-huan-kong-ge-lcof.cpp) 
```cpp
class Solution {
public:
    string replaceSpace(string s) {
        int cnt = 0, len = s.size();
        for (auto &c : s) {
            if (c == ' ') {
                cnt++;
            }
        }
        s.resize(len + 2*cnt);
        for (int i = s.size() - 1, j = len - 1;  i != j; i--, j-- ) {
            if (s[j] != ' ') {
                s[i] = s[j];
            } else {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        }

        return s;
    }
};
```


## 相关话题

- [字符串](https://leetcode-cn.com/tag/string) 


## 相似题目



## Links

- [Prev](../xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/README.md) 
- [Next](../cong-wei-dao-tou-da-yin-lian-biao-lcof/README.md) 

