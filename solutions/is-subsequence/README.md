
# [](https://leetcode-cn.com/problems/is-subsequence)

## 题目描述



## 题解

### c [🔗](is-subsequence.c) 
```c
bool isSubsequence(char * s, char * t){
    while (*s && *t) s += (*s == *t++);
    return !*s;
}
```
### cpp [🔗](is-subsequence.cpp) 
```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index = 0;
        for (auto c : t) {
            if (index < s.size() && c == s[index]) {
                index++;
            }
        }
        return index == s.size();
    }
};
```
### golang [🔗](is-subsequence.go) 
```golang
func isSubsequence(s string, t string) bool {
    m, n := len(s), len(t)
    dp := make([][]int, m+1)
    for i := 0; i <= m; i++ {
        dp[i] = make([]int, n+1)
    }

    for i := 1; i <= m; i++ {
        for j := 1; j <= n; j++ {
            if s[i-1] == t[j-1] {
                dp[i][j] = dp[i-1][j-1] + 1
            } else {
                dp[i][j] = dp[i][j-1]
            }
        }
    }
    return dp[m][n] == len(s)
}
```


## 相关话题



## 相似题目



## Links

- [Prev](../find-the-difference/README.md) 
- [Next](../utf-8-validation/README.md) 

