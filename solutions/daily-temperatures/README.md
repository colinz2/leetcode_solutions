
# [每日温度](https://leetcode-cn.com/problems/daily-temperatures)

## 题目描述

<p>给定一个整数数组&nbsp;<code>temperatures</code>&nbsp;，表示每天的温度，返回一个数组&nbsp;<code>answer</code>&nbsp;，其中&nbsp;<code>answer[i]</code>&nbsp;是指在第 <code>i</code> 天之后，<span style="font-size:10.5pt"><span style="font-family:Calibri"><span style="font-size:10.5000pt"><span style="font-family:宋体"><font face="宋体">才会有更高的温度</font></span></span></span></span>。如果气温在这之后都不会升高，请在该位置用&nbsp;<code>0</code> 来代替。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> <code>temperatures</code> = [73,74,75,71,69,72,76,73]
<strong>输出:</strong>&nbsp;[1,1,4,2,1,1,0,0]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> temperatures = [30,40,50,60]
<strong>输出:</strong>&nbsp;[1,1,1,0]
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> temperatures = [30,60,90]
<strong>输出: </strong>[1,1,0]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;temperatures.length &lt;= 10<sup>5</sup></code></li>
	<li><code>30 &lt;=&nbsp;temperatures[i]&nbsp;&lt;= 100</code></li>
</ul>


## 题解

### c [🔗](daily-temperatures.c) 
```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *dailyTemperatures(int *T, int TSize, int *returnSize)
{
    int monoStack[TSize];
    memset(monoStack, 0, sizeof(int) * TSize);
    int stackTop = -1;
    int tIter = 0;

    int *res = (int *)malloc(sizeof(int) * TSize);
    memset(res, 0, sizeof(int) * TSize);

    while (tIter < TSize) {
        /* monoStack[stackTop]是栈顶元素在T中的下标，T[monoStack[stackTop]] 才是真正的栈顶温度 */
        while (stackTop != -1 && T[monoStack[stackTop]] < T[tIter]) {
            int r = monoStack[stackTop];
            stackTop--;
            
            res[r] = tIter - r;
        }
        monoStack[++stackTop] = tIter++;        
    }
    *returnSize = TSize;
    return res;
}

```
### cpp [🔗](daily-temperatures.cpp) 
```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // 单调栈，保存位置
        int len = temperatures.size();
        vector<int> res(len, 0);
        vector<int> st(len, 0);

        int stLen = 0;

        for (int i = 0; i < len; i++) {
            while (stLen > 0 && temperatures[i] > temperatures[st[stLen-1]]) {
                res[st[stLen-1]] = i - st[stLen-1];
                stLen--;
            }
            st[stLen++] = i;
        }

        return res;
    }
};
```
### golang [🔗](daily-temperatures.go) 
```golang
func dailyTemperatures(temperatures []int) []int {
    res := make([]int, len(temperatures))
    stack := []int{}

    for i, t := range temperatures {
        for len(stack) > 0 {
            top := stack[len(stack)-1]
            if t > temperatures[top] {
                res[top] = i - top
                stack = stack[:len(stack)-1]
            } else {
                break;
            }
        }
        stack = append(stack, i)
    }

    for _, leftIndex := range stack {
        res[leftIndex] = 0
    }

    return res
}
```
### java [🔗](daily-temperatures.java) 
```java
class Solution {
    public int[] dailyTemperatures(int[] T) {
        int[] res = new int[T.length];
        for (int i = 0; i < T.length; i++) {
            for (int j =  i + 1; j < T.length; j++) {
                if (T[j] > T[i]) {
                    res[i] = j - i;
                    break;
                }
            }
        }
        return res;
    }
}
```


## 相关话题

- [栈](https://leetcode-cn.com/tag/stack) 
- [数组](https://leetcode-cn.com/tag/array) 
- [单调栈](https://leetcode-cn.com/tag/monotonic-stack) 


## 相似题目

- [下一个更大元素 I](../next-greater-element-i/README.md)  [Easy] 


## Links

- [Prev](../split-linked-list-in-parts/README.md) 
- [Next](../to-lower-case/README.md) 

