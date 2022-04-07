
# [](https://leetcode-cn.com/problems/unique-morse-code-words)

## 题目描述



## 题解

### cpp [🔗](unique-morse-code-words.cpp) 
```cpp
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string morse_code[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> unique_ms;
        for (string& word : words) {
            string morse_string = "";
            for (int i = 0; i < word.size(); i++) {
                morse_string += morse_code[word[i] - 'a'];
            }
            unique_ms.insert(morse_string);
        }
        
        return unique_ms.size();
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../design-hashmap/README.md) 
- [Next](../subdomain-visit-count/README.md) 

