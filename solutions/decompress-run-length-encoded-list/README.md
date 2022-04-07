
# [](https://leetcode-cn.com/problems/decompress-run-length-encoded-list)

## 题目描述



## 题解

### cpp [🔗](decompress-run-length-encoded-list.cpp) 
```cpp
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i += 2) {
            int freq = nums[i];
            for (int j = 0; j < freq; j++) {
                res.push_back(nums[i+1]);
            }
        }
        return res;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../n-th-tribonacci-number/README.md) 
- [Next](../longest-common-subsequence/README.md) 

