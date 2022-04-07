
# [](https://leetcode-cn.com/problems/unique-email-addresses)

## 题目描述



## 题解

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


## 相关话题



## 相似题目



## Links

- [Prev](../reverse-only-letters/README.md) 
- [Next](../number-of-recent-calls/README.md) 

