
# [](https://leetcode-cn.com/problems/lemonade-change)

## 题目描述



## 题解

### cpp [🔗](lemonade-change.cpp) 
```cpp
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5 = 0, cnt10 = 0;
        for (auto& bill : bills) {
            switch (bill) {
                case 5:
                    cnt5++;
                    break;
                case 10:
                    cnt10++;
                    if (cnt5 > 0) cnt5--;
                    else return false;
                    break;
                case 20:
                    if (cnt10 > 0) {
                        cnt10--;
                        if (cnt5 >= 1) cnt5--;
                        else return false;
                    } else {
                        if (cnt5 >=3 ) cnt5 -= 3;
                        else return false;
                    }
                    break;
                default:
                    return false;
            }
        }
        return true;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../peak-index-in-a-mountain-array/README.md) 
- [Next](../transpose-matrix/README.md) 

