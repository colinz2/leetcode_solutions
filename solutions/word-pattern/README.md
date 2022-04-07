
# [](https://leetcode-cn.com/problems/word-pattern)

## 题目描述



## 题解

### golang [🔗](word-pattern.go) 
```golang
func wordPattern(pattern string, s string) bool {
    words := strings.Fields(s)
    if len(pattern) != len(words) {
        return false
    }
    seen := make(map[byte]int)
    seenWord := make(map[string]int)
    for i := 0; i < len(pattern); i++ {
        if seen[pattern[i]] != seenWord[words[i]] {
            return false
        }
        seen[pattern[i]] = i + 1
        seenWord[words[i]] = i + 1
    }
    return true
}
```


## 相关话题



## 相似题目



## Links

- [Prev](../game-of-life/README.md) 
- [Next](../nim-game/README.md) 

