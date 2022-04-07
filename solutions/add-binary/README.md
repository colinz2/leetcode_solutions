
# [](https://leetcode-cn.com/problems/add-binary)

## 题目描述



## 题解

### cpp [🔗](add-binary.cpp) 
```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        string base , adder;
        if (a.size() > b.size()) {
            base = a;
            adder = b;
        } else {
            base = b;
            adder = a;
        }

        int carry = 0;
        for (int i = base.size() - 1, j = adder.size() - 1 ; i >= 0; i--, j--) {
            int sum = 0;
            if (j >= 0) {
               sum = (base[i] - 0x30) + (adder[j] - 0x30) + carry;
            } else {
                sum = base[i] - 0x30 + carry;
            }
            base[i] = (sum % 2) + 0x30;
            carry = sum / 2;
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

- [Prev](../plus-one/README.md) 
- [Next](../sqrtx/README.md) 

