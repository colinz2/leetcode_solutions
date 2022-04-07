
# [](https://leetcode-cn.com/problems/most-common-word)

## 题目描述



## 题解

### cpp [🔗](most-common-word.cpp) 
```cpp
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string res;
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        unordered_set<string> ban(banned.begin(), banned.end());
        vector<string> words;
        unordered_map<string, int> freq;

        bool next_islower = false, pre_islower = false;
        int b = 0, e = 0;
        int max_cnt = 0;
        for (int i = 0; i < paragraph.size(); i++) {
            next_islower = islower(paragraph[i + 1]);
            if (islower(paragraph[i])) {
                if (!pre_islower) {
                    b = i;
                }
                if (!next_islower) {
                    e = i + 1;
                    string word = paragraph.substr(b, e - b);
                    if (ban.find(word) == ban.end()) {
                        freq[word] += 1;
                        if (freq[word] > max_cnt) {
                            max_cnt = freq[word];
                            res = word;
                        }
                    }
                }
                pre_islower = true;
            } else {
                pre_islower = false;
            }
        }

        return res;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../binary-tree-pruning/README.md) 
- [Next](../design-linked-list/README.md) 

