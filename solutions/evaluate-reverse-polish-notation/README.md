
# [逆波兰表达式求值](https://leetcode-cn.com/problems/evaluate-reverse-polish-notation)

## 题目描述

<p>根据<a href="https://baike.baidu.com/item/%E9%80%86%E6%B3%A2%E5%85%B0%E5%BC%8F/128437" target="_blank"> 逆波兰表示法</a>，求表达式的值。</p>

<p>有效的算符包括&nbsp;<code>+</code>、<code>-</code>、<code>*</code>、<code>/</code>&nbsp;。每个运算对象可以是整数，也可以是另一个逆波兰表达式。</p>

<p><b>注意&nbsp;</b>两个整数之间的除法只保留整数部分。</p>

<p>可以保证给定的逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>tokens = ["2","1","+","3","*"]
<strong>输出：</strong>9
<strong>解释：</strong>该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>tokens = ["4","13","5","/","+"]
<strong>输出：</strong>6
<strong>解释：</strong>该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
</pre>

<p><strong>示例&nbsp;3：</strong></p>

<pre>
<strong>输入：</strong>tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
<strong>输出：</strong>22
<strong>解释：</strong>该算式转化为常见的中缀算术表达式为：
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= tokens.length &lt;= 10<sup>4</sup></code></li>
	<li><code>tokens[i]</code>&nbsp;是一个算符（<code>"+"</code>、<code>"-"</code>、<code>"*"</code> 或 <code>"/"</code>），或是在范围 <code>[-200, 200]</code> 内的一个整数</li>
</ul>

<p>&nbsp;</p>

<p><strong>逆波兰表达式：</strong></p>

<p>逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。</p>

<ul>
	<li>平常使用的算式则是一种中缀表达式，如 <code>( 1 + 2 ) * ( 3 + 4 )</code> 。</li>
	<li>该算式的逆波兰表达式写法为 <code>( ( 1 2 + ) ( 3 4 + ) * )</code> 。</li>
</ul>

<p>逆波兰表达式主要有以下两个优点：</p>

<ul>
	<li>去掉括号后表达式无歧义，上式即便写成 <code>1 2 + 3 4 + * </code>也可以依据次序计算出正确结果。</li>
	<li>适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中</li>
</ul>


## 题解

### cpp [🔗](evaluate-reverse-polish-notation.cpp) 
```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        std::function<void(std::function<int(int,int)>)> eval = [&st]( std::function<int(int,int)> func) {
            int var1 = 0, var2 = 0;
            var1 = st.top(), st.pop();
            var2 = st.top(), st.pop();
            st.push(func(var2, var1));
        };

        for (auto &token : tokens) {
            switch (token[0]) {
                case '+':
                    eval([](int a, int b) {return a + b;});
                    break;
                case '-':
                    if (token.size() > 1) st.push(stoi(token));
                    else eval([](int a, int b) {return a - b;}); 
                    break;
                case '*':
                    eval([](int a, int b) {return a * b;}); 
                    break;
                case '/':
                    eval([](int a, int b) {return a / b;}); 
                    break;
                default:
                    st.push(stoi(token));
            }
        }
        return st.top();
    }
};
```


## 相关话题

- [栈](https://leetcode-cn.com/tag/stack) 
- [数组](https://leetcode-cn.com/tag/array) 
- [数学](https://leetcode-cn.com/tag/math) 


## 相似题目



## Links

- [Prev](../sort-list/README.md) 
- [Next](../reverse-words-in-a-string/README.md) 

