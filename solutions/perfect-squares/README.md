
# [](https://leetcode-cn.com/problems/perfect-squares)

## 题目描述



## 题解

### cpp [🔗](perfect-squares.cpp) 
```cpp
class Solution {

public:
    int numSquares(int n) {

        vector<int> mem(n + 1, -1);

        return numSquares(n, mem);
    }

private:
    int numSquares(int n, vector<int>& mem){

        if(n == 0)
            return 0;

        if(mem[n] != -1)
            return mem[n];

        int res = INT_MAX;
        for(int i = 1; n - i * i >= 0; i ++ )
            res = min(res, 1 + numSquares(n - i * i, mem));
        return mem[n] = res;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../first-bad-version/README.md) 
- [Next](../move-zeroes/README.md) 

