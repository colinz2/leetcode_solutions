
# [独特的电子邮件地址](https://leetcode-cn.com/problems/unique-email-addresses)

## 题目描述

<p>每个 <strong>有效电子邮件地址</strong> 都由一个 <strong>本地名</strong> 和一个 <strong>域名</strong> 组成，以 <code>'@'</code> 符号分隔。除小写字母之外，电子邮件地址还可以含有一个或多个&nbsp;<code>'.'</code> 或 <code>'+'</code> 。</p>

<ul>
	<li>例如，在&nbsp;<code>alice@leetcode.com</code>中，&nbsp;<code>alice</code>&nbsp;是 <strong>本地名</strong> ，而&nbsp;<code>leetcode.com</code>&nbsp;是 <strong>域名</strong> 。</li>
</ul>

<p>如果在电子邮件地址的<strong> 本地名 </strong>部分中的某些字符之间添加句点（<code>'.'</code>），则发往那里的邮件将会转发到本地名中没有点的同一地址。请注意，此规则 <strong>不适用于域名</strong> 。</p>

<ul>
	<li>例如，<code>"alice.z@leetcode.com”</code> 和 <code>“alicez@leetcode.com”</code>&nbsp;会转发到同一电子邮件地址。</li>
</ul>

<p>如果在<strong> 本地名 </strong>中添加加号（<code>'+'</code>），则会忽略第一个加号后面的所有内容。这允许过滤某些电子邮件。同样，此规则 <strong>不适用于域名</strong> 。</p>

<ul>
	<li>例如 <code>m.y+name@email.com</code> 将转发到 <code>my@email.com</code>。</li>
</ul>

<p>可以同时使用这两个规则。</p>

<p>给你一个字符串数组 <code>emails</code>，我们会向每个 <code>emails[i]</code> 发送一封电子邮件。返回实际收到邮件的不同地址数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
<strong>输出：</strong>2
<strong>解释：</strong>实际收到邮件的是 "testemail@leetcode.com" 和 "testemail@lee.tcode.com"。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>emails = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]
<strong>输出：</strong>3
</pre>

<p><br />
<strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= emails.length &lt;= 100</code></li>
	<li><code>1 &lt;= emails[i].length&nbsp;&lt;= 100</code></li>
	<li><code>emails[i]</code> 由小写英文字母、<code>'+'</code>、<code>'.'</code> 和 <code>'@'</code> 组成</li>
	<li>每个 <code>emails[i]</code> 都包含有且仅有一个 <code>'@'</code> 字符</li>
	<li>所有本地名和域名都不为空</li>
	<li>本地名不会以 <code>'+'</code> 字符作为开头</li>
</ul>


## 题解

### golang [🔗](unique-email-addresses.go) 
```golang
func numUniqueEmails(emails []string) int {
	seen := make(map[string]bool)
	for _, email := range emails {
		comp := strings.Split(email, "@")
		if len(comp) == 2 {
			comp[0] = strings.Split(comp[0], "+")[0]
			comp[0] = strings.Replace(comp[0], ".", "", -1)
			finalEmail := strings.Join(comp, "@")
			fmt.Println(finalEmail)
			seen[finalEmail] = true
		}
	}
	return len(seen)
}
```
### python3 [🔗](unique-email-addresses.py) 
```python3
class Solution:
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        seen = set()
        for email in emails:
            sep = email.split("@")
            sep[0] = sep[0].split("+")[0]
            sep[0] = sep[0].replace(".", "")

            seen.add("@".join(sep))
        return len(seen)
```
### cpp [🔗](unique-email-addresses.cpp) 
```cpp
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> rd;
        for (string email : emails) {
            auto at = email.find("@");
            if (at == string::npos) {
                continue;
            }
            string name = email.substr(0, at);
            auto plus = name.find('+');
            if (plus != string::npos) {
                name = name.substr(0, plus);
            }
            string res = "";
            for (char c: name)
                if (c != '.')
                    res += c;
            res += email.substr(at);
            rd.insert(res);
        }
        return rd.size();
    }
};
```


## 相关话题

- [数组](../../tags/array.md) 
- [哈希表](../../tags/hash-table.md) 
- [字符串](../../tags/string.md) 


## 相似题目



## Links

- [Prev](../reverse-only-letters/README.md) 
- [Next](../number-of-recent-calls/README.md) 

