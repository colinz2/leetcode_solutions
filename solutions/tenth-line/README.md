
# [第十行](https://leetcode-cn.com/problems/tenth-line)

## 题目描述

<p>给定一个文本文件&nbsp;<code>file.txt</code>，请只打印这个文件中的第十行。</p>

<p><strong>示例:</strong></p>

<p>假设&nbsp;<code>file.txt</code> 有如下内容：</p>

<pre>Line 1
Line 2
Line 3
Line 4
Line 5
Line 6
Line 7
Line 8
Line 9
Line 10
</pre>

<p>你的脚本应当显示第十行：</p>

<pre>Line 10
</pre>

<p><strong>说明:</strong><br>
1. 如果文件少于十行，你应当输出什么？<br>
2. 至少有三种不同的解法，请尝试尽可能多的方法来解题。</p>


## 题解

### bash [🔗](tenth-line.bash) 
```bash
# Read from the file file.txt and output the tenth line to stdout.
awk 'NR==10{print $0}' file.txt


```


## 相关话题

- [](../../tags/shell.md) 


## 相似题目



## Links

- [Prev](../number-of-1-bits/README.md) 
- [Next](../house-robber/README.md) 

