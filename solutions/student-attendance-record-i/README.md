
# [](https://leetcode-cn.com/problems/student-attendance-record-i)

## 题目描述



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



## 相似题目



## Links

- [Prev](../number-of-provinces/README.md) 
- [Next](../reverse-words-in-a-string-iii/README.md) 

