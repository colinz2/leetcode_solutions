
# [Fizz Buzz](https://leetcode-cn.com/problems/fizz-buzz)

## 题目描述

<p>给你一个整数 <code>n</code> ，找出从 <code>1</code> 到 <code>n</code> 各个整数的 Fizz Buzz 表示，并用字符串数组 <code>answer</code>（<strong>下标从 1 开始</strong>）返回结果，其中：</p>

<ul>
	<li><code>answer[i] == "FizzBuzz"</code> 如果 <code>i</code> 同时是 <code>3</code> 和 <code>5</code> 的倍数。</li>
	<li><code>answer[i] == "Fizz"</code> 如果 <code>i</code> 是 <code>3</code> 的倍数。</li>
	<li><code>answer[i] == "Buzz"</code> 如果 <code>i</code> 是 <code>5</code> 的倍数。</li>
	<li><code>answer[i] == i</code> （以字符串形式）如果上述条件全不满足。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>["1","2","Fizz"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 5
<strong>输出：</strong>["1","2","Fizz","4","Buzz"]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 15
<strong>输出：</strong>["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
</ul>


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

- [数学](../../tags/math.md) 
- [字符串](../../tags/string.md) 
- [模拟](../../tags/simulation.md) 


## 相似题目



## Links

- [Prev](../longest-palindrome/README.md) 
- [Next](../add-strings/README.md) 

