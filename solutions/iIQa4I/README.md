
# [](https://leetcode-cn.com/problems/iIQa4I)

## 题目描述



## 题解

### cpp [🔗](iIQa4I.cpp) 
```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        
        stack<int> st;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return res;
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../aMhZSa/README.md) 
- [Next](../opLdQZ/README.md) 

