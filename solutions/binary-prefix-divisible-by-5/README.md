
# [](https://leetcode-cn.com/problems/binary-prefix-divisible-by-5)

## 题目描述



## 题解

### cpp [🔗](binary-prefix-divisible-by-5.cpp) 
```cpp
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int size = nums.size();
        vector<bool> res(size, false);
        int num = 0;
        for (int i = 0; i < size; i++) {
            num = (num << 1) + nums[i];
            num = num % 5;
            res[i] = (num == 0);
        }
        return res;
    }
};
```
### golang [🔗](binary-prefix-divisible-by-5.go) 
```golang
func prefixesDivBy5(nums []int) []bool {
    ans := make([]bool, len(nums))
    x := 0
    // 如果x为和而不取模，有溢出问题啊！！！
    for i, v := range nums {
        x = (x<<1 | v) % 5
        ans[i] = x == 0
    }
    return ans
}
```
### java [🔗](binary-prefix-divisible-by-5.java) 
```java
class Solution {
    // 有限状态机 DFA ？
    public List<Boolean> prefixesDivBy5(int[] nums) {
        List<Boolean> res = new ArrayList<>();
        if (nums.length < 1) {
            return res;
        }
        int StateSet[][] = new int[][]{
                {0, 1},
                {2, 3},
                {4, 0},
                {1, 2},
                {3, 4}
        };
        int state = 0;
        for (int i = 0; i < nums.length; i++) {
            state = StateSet[state][nums[i]];  //转换后的状态
            if (state == 0) {
                res.add(Boolean.TRUE);
            } else {
                res.add(Boolean.FALSE);
            }
        }
        return res;
    }
}
```


## 相关话题



## 相似题目



## Links

- [Prev](../fixed-point/README.md) 
- [Next](../number-of-enclaves/README.md) 

