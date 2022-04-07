
# [](https://leetcode-cn.com/problems/add-strings)

## 题目描述



## 题解

### cpp [🔗](add-strings.cpp) 
```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        string base = num2, adder = num1;
        int carry = 0;
        if (num1.size() > num2.size()) {
            base = num1;
            adder = num2;
        }
        for (int i = base.size() - 1, j = adder.size() - 1 ; i >= 0; i--, j--) {
            int sum = 0;
            if (j >= 0) {
                sum = (base[i] - 0x30) + (adder[j] - 0x30) + carry;
            } else {
                sum = base[i] - 0x30 + carry;
            }
            base[i] = (sum % 10) + 0x30;
            carry = sum / 10;
        }

        if (carry) {
            base.insert(base.begin(), '1');
        }
        return base;
    }
};

```


## 相关话题



## 相似题目



## Links

- [Prev](../fizz-buzz/README.md) 
- [Next](../number-of-segments-in-a-string/README.md) 

