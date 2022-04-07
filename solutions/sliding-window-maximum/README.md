
# [](https://leetcode-cn.com/problems/sliding-window-maximum)

## 题目描述



## 题解

### cpp [🔗](sliding-window-maximum.cpp) 
```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<std::pair<int, int>> pq;
        for (int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }
        vector<int> res = {pq.top().first};

        // [l, r] window
        int l = 1, r = k;
        while (r < nums.size()) {
            while (!pq.empty() && pq.top().second < l) {
                pq.pop();
            }
            pq.push({nums[r], r});
            res.push_back(pq.top().first);
            l++;
            r++;
        }
        return res;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../product-of-array-except-self/README.md) 
- [Next](../valid-anagram/README.md) 

