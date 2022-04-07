
# [](https://leetcode-cn.com/problems/remove-element)

## 题目描述



## 题解

### cpp [🔗](remove-element.cpp) 
```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0, k = nums.size();
        while (j < k) {
            if (nums[j] == val) {
                nums[j] = nums[--k];
            } else {
                // 注意这里是 else，避免重复的val之间移动的问题
                j++;
            }
        }

        return k;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../remove-duplicates-from-sorted-array/README.md) 
- [Next](../implement-strstr/README.md) 

