
# [复原 IP 地址](https://leetcode-cn.com/problems/restore-ip-addresses)

## 题目描述

<p><strong>有效 IP 地址</strong> 正好由四个整数（每个整数位于 <code>0</code> 到 <code>255</code> 之间组成，且不能含有前导 <code>0</code>），整数之间用 <code>'.'</code> 分隔。</p>

<ul>
	<li>例如：<code>"0.1.2.201"</code> 和<code> "192.168.1.1"</code> 是 <strong>有效</strong> IP 地址，但是 <code>"0.011.255.245"</code>、<code>"192.168.1.312"</code> 和 <code>"192.168@1.1"</code> 是 <strong>无效</strong> IP 地址。</li>
</ul>

<p>给定一个只包含数字的字符串 <code>s</code> ，用以表示一个 IP 地址，返回所有可能的<strong>有效 IP 地址</strong>，这些地址可以通过在 <code>s</code> 中插入&nbsp;<code>'.'</code> 来形成。你 <strong>不能</strong>&nbsp;重新排序或删除 <code>s</code> 中的任何数字。你可以按 <strong>任何</strong> 顺序返回答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "25525511135"
<strong>输出：</strong>["255.255.11.135","255.255.111.35"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "0000"
<strong>输出：</strong>["0.0.0.0"]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "101023"
<strong>输出：</strong>["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 20</code></li>
	<li><code>s</code> 仅由数字组成</li>
</ul>


## 题解

### cpp [🔗](restore-ip-addresses.cpp) 
```cpp
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> ip;
        if (s.size() < 4 || s.size() > 12) return res;
        solve(s, 0, ip, res);
        return res;
    }

private:
    void solve(string s, int index, vector<string> &ip, vector<string> &res) {
        if (index == s.size()) {
            if (ip.size() == 4) {
                string ip_addr = ip[0] + "." + ip[1] + "." + ip[2] + "." + ip[3];
                res.push_back(ip_addr);
            }
            return;
        }
        for (int step = 1; step <= 3; step++) {
            //s.size() - index is the lefted chars count,  the rule :
            //e.g.
            //have restored 1 of 4 ip number, the lefted chars count must less than 9 "3*(4 - 1)"
            if (3 * (4 - ip.size())  < s.size() - index) {
                //cout << "\U0001f602\U0001f602\U0001f602\U0001f602" << endl;
                break;
            }
            if (index + step > s.size()) {
                break;
            }
            //first byte can't be 0, if string size longer than 1
            if (step > 1 && s[index] == '0') {
                continue;
            }
            string tmp = s.substr(index, step);
            int num = stoi(tmp);
            if (num >= 0 && num <= 255) {
                ip.push_back(tmp);
                solve(s, index + step, ip, res);
                ip.pop_back();
            }
        }
    }
};
```


## 相关话题

- [字符串](https://leetcode-cn.com/tag/string) 
- [回溯](https://leetcode-cn.com/tag/backtracking) 


## 相似题目



## Links

- [Prev](../reverse-linked-list-ii/README.md) 
- [Next](../binary-tree-inorder-traversal/README.md) 

