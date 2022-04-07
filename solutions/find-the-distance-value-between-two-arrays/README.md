
# [](https://leetcode-cn.com/problems/find-the-distance-value-between-two-arrays)

## 题目描述



## 题解

### cpp [🔗](find-the-distance-value-between-two-arrays.cpp) 
```cpp
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int len1 = arr1.size(), len2 = arr2.size();
        int res = 0;
        for (int i = 0; i < len1; i++) {
            int cnt = 0;
            for (int j = 0; j < len2; j++) {
                if (abs(arr1[i] - arr2[j]) > d) {
                    cnt++;
                }
            }
            res += cnt == len2;
        }
        return res;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../find-numbers-with-even-number-of-digits/README.md) 
- [Next](../build-an-array-with-stack-operations/README.md) 

