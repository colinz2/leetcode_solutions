
# [](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof)

## 题目描述



## 题解

### cpp [🔗](xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof.cpp) 
```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int l = 0, r = numbers.size() - 1;
        if (numbers.size() == 0) return -1;
        // 二分查找
        // 确定 target 为最右端 r
        // [5,1,2,3,4]
        // 如果 num[mid] < num[r], 则 mid右边全部是有序的(可以用反证法证明), 在左侧找，r = mid
        // 如果 num[mid] == num[r], 则 r = r - 1
        // 如果 num[mid] > num[r], 则 可以确定在 mid 右侧找， l = mid + 1

        while (l <= r) {
            int mid = (r-l)/2 + l;
            if (numbers[mid] > numbers[r]) {
                l = mid + 1;
            } else if (numbers[mid] < numbers[r]){
                r = mid;
            } else {
                r = r - 1;
            }
        }

        return numbers[l];
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../shu-zu-zhong-zhong-fu-de-shu-zi-lcof/README.md) 
- [Next](../ti-huan-kong-ge-lcof/README.md) 

