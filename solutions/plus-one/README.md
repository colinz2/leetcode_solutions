
# [](https://leetcode-cn.com/problems/plus-one)

## 题目描述



## 题解

### cpp [🔗](plus-one.cpp) 
```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = false;
        for (auto i = digits.size(); i > 0; i--) {
            digits[i - 1] += 1;
            if (digits[i - 1] == 10) {
                digits[i - 1] = 0;
                carry = true;
            } else {
                carry = false;
                break;
            }
        }
        
        if (carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../minimum-path-sum/README.md) 
- [Next](../add-binary/README.md) 

