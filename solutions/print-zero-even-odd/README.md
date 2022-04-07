
# [打印零与奇偶数](https://leetcode-cn.com/problems/print-zero-even-odd)

## 题目描述

<p>现有函数 <code>printNumber</code> 可以用一个整数参数调用，并输出该整数到控制台。</p>

<ul>
	<li>例如，调用 <code>printNumber(7)</code> 将会输出 <code>7</code> 到控制台。</li>
</ul>

<p>给你类 <code>ZeroEvenOdd</code> 的一个实例，该类中有三个函数：<code>zero</code>、<code>even</code> 和 <code>odd</code> 。<code>ZeroEvenOdd</code> 的相同实例将会传递给三个不同线程：</p>

<ul>
	<li><strong>线程 A：</strong>调用 <code>zero()</code> ，只输出 <code>0</code></li>
	<li><strong>线程 B：</strong>调用 <code>even()</code> ，只输出偶数</li>
	<li><strong>线程 C：</strong>调用 <code>odd()</code> ，只输出奇数</li>
</ul>

<p>修改给出的类，以输出序列 <code>"010203040506..."</code> ，其中序列的长度必须为 <code>2n</code> 。</p>

<p>实现 <code>ZeroEvenOdd</code> 类：</p>

<ul>
	<li><code>ZeroEvenOdd(int n)</code> 用数字 <code>n</code> 初始化对象，表示需要输出的数。</li>
	<li><code>void zero(printNumber)</code> 调用 <code>printNumber</code> 以输出一个 0 。</li>
	<li><code>void even(printNumber)</code> 调用<code>printNumber</code> 以输出偶数。</li>
	<li><code>void odd(printNumber)</code> 调用 <code>printNumber</code> 以输出奇数。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>"0102"
<strong>解释：</strong>三条线程异步执行，其中一个调用 zero()，另一个线程调用 even()，最后一个线程调用odd()。正确的输出为 "0102"。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 5
<strong>输出：</strong>"0102030405"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>


## 题解

### cpp [🔗](print-zero-even-odd.cpp) 
```cpp
class ZeroEvenOdd {
private:
    int n;
    int next;
    std::mutex mu_;
    std::condition_variable cv_;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->next = 0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        std::unique_lock<std::mutex> lk(mu_);
        for (int i = 1; i <= n; i++) {
          if (i > 1) lk.lock();
          cv_.wait(lk, [this]{ return next == 0;});
          printNumber(0);
          next = 2 - (i)%2;
          cv_.notify_all();
          lk.unlock();
        }
    }

    void even(function<void(int)> printNumber) {
        std::unique_lock<std::mutex> lk(mu_);
        for (int i = 2; i <= n; i += 2) {
          if (i > 2) lk.lock();
          cv_.wait(lk, [this]{ return next & 2; });
          printNumber(i);
          next = 0;
          cv_.notify_all();
          lk.unlock();
        }       
    }

    void odd(function<void(int)> printNumber) {
        std::unique_lock<std::mutex> lk(mu_);
        for (int i = 1; i <= n; i += 2) {
          if (i > 1) lk.lock();
          cv_.wait(lk, [this]{ return next & 1;});
          printNumber(i);
          next = 0;
          lk.unlock();
          cv_.notify_all();
        }   
    }
};
```


## 相关话题

- [多线程](../../tags/concurrency.md) 


## 相似题目

- [交替打印 FooBar](../print-foobar-alternately/README.md)  [Medium] 


## Links

- [Prev](../design-bounded-blocking-queue/README.md) 
- [Next](../n-th-tribonacci-number/README.md) 

