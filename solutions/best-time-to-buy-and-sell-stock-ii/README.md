
# [](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii)

## 题目描述



## 题解

### cpp [🔗](best-time-to-buy-and-sell-stock-ii.cpp) 
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            // 把所有可能的利润都算上，自然就是最大的总利润
            if (prices[i] > prices[i - 1]) {
                res += prices[i] - prices[i - 1];
            }
        }
        return res;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../best-time-to-buy-and-sell-stock/README.md) 
- [Next](../binary-tree-maximum-path-sum/README.md) 

