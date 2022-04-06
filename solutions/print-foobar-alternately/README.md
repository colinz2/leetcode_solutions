
# [交替打印 FooBar](https://leetcode-cn.com/problems/print-foobar-alternately)

## 题目描述

<p>给你一个类：</p>

<pre>
class FooBar {
  public void foo() {
&nbsp; &nbsp; for (int i = 0; i &lt; n; i++) {
&nbsp; &nbsp; &nbsp; print("foo");
&nbsp;   }
  }

  public void bar() {
&nbsp; &nbsp; for (int i = 0; i &lt; n; i++) {
&nbsp; &nbsp; &nbsp; print("bar");
&nbsp; &nbsp; }
  }
}
</pre>

<p>两个不同的线程将会共用一个 <code>FooBar</code>&nbsp;实例：</p>

<ul>
	<li>线程 A 将会调用&nbsp;<code>foo()</code>&nbsp;方法，而</li>
	<li>线程 B 将会调用&nbsp;<code>bar()</code>&nbsp;方法</li>
</ul>

<p>请设计修改程序，以确保 <code>"foobar"</code> 被输出 <code>n</code> 次。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>"foobar"
<strong>解释：</strong>这里有两个线程被异步启动。其中一个调用 foo() 方法, 另一个调用 bar() 方法，"foobar" 将被输出一次。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>"foobarfoobar"
<strong>解释：</strong>"foobar" 将被输出两次。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>


## 题解

### cpp [🔗](print-foobar-alternately.cpp) 
```cpp
class FooBar {
private:
    int n;
    int foo_cnt_;
    int bar_cnt_;
    std::mutex mu_;
    std::condition_variable cv_;
public:
    FooBar(int n) {
        this->n = n;
        this->foo_cnt_ = 0;
        this->bar_cnt_ = 0;
    }

    void foo(function<void()> printFoo) {
        std::unique_lock<std::mutex> lk(mu_);
        for (int i = 0; i < n; i++) {
          if (i > 0) lk.lock();
          cv_.wait(lk, [this]{
            return foo_cnt_ == bar_cnt_;
          });
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
          foo_cnt_++;
          lk.unlock();
          cv_.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        std::unique_lock<std::mutex> lk(mu_);
        for (int i = 0; i < n; i++) {
          if (i > 0) lk.lock();
          cv_.wait(lk, [this]{
            return foo_cnt_ == bar_cnt_ + 1;
          });
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
          bar_cnt_++;
          lk.unlock();
          cv_.notify_one();
        }
    }
};
```


## 相关话题

- [多线程](https://leetcode-cn.com/tag/concurrency) 


## 相似题目

- [按序打印](../print-in-order/README.md)  [Easy] 
- [打印零与奇偶数](../print-zero-even-odd/README.md)  [Medium] 


## Links

- [Prev](../building-h2o/README.md) 
- [Next](../print-in-order/README.md) 

