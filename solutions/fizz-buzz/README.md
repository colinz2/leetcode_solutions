
# [](https://leetcode-cn.com/problems/fizz-buzz)

## 题目描述



## 题解

### cpp [🔗](fizz-buzz.cpp) 
```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        //c++ std::to_string
        for (int i = 1; i <= n; i++){
            if (i%15 == 0) result.push_back("FizzBuzz");
            else if (i%3 == 0) result.push_back("Fizz");
            else if (i%5 == 0) result.push_back("Buzz");
            else result.push_back(to_string(i));
        }
        
        return result;
    }
};
```
### python3 [🔗](fizz-buzz.py) 
```python3
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        res = []
        i = 1
        while i <= n:
            if i % 15 == 0:
                res.append("FizzBuzz")
            elif i % 5 == 0:
                res.append("Buzz")
            elif i % 3 == 0:
                res.append("Fizz")
            else:
                res.append(str(i))
            i += 1
        return res

```
### rust [🔗](fizz-buzz.rs) 
```rust
impl Solution {
    pub fn fizz_buzz(n: i32) -> Vec<String> {
        let mut i = 1;
        let mut res = Vec::new();

        while i <= n {
            if i % 15 == 0 {
                res.push("FizzBuzz".to_string());
            } else if (i % 5 == 0) {
                res.push("Buzz".to_string());
            } else if (i % 3 == 0) {
                res.push("Fizz".to_string());
            } else {
                res.push(i.to_string());
            }
            i += 1;
        }
        return res;
    }
}
```


## 相关话题



## 相似题目



## Links

- [Prev](../longest-palindrome/README.md) 
- [Next](../add-strings/README.md) 

