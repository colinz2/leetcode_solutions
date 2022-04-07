
# [按序打印](https://leetcode-cn.com/problems/print-in-order)

## 题目描述

<p>给你一个类：</p>

<pre>
public class Foo {
&nbsp; public void first() { print("first"); }
&nbsp; public void second() { print("second"); }
&nbsp; public void third() { print("third"); }
}</pre>

<p>三个不同的线程 A、B、C 将会共用一个&nbsp;<code>Foo</code>&nbsp;实例。</p>

<ul>
	<li>线程 A 将会调用 <code>first()</code> 方法</li>
	<li>线程 B 将会调用&nbsp;<code>second()</code> 方法</li>
	<li>线程 C 将会调用 <code>third()</code> 方法</li>
</ul>

<p>请设计修改程序，以确保 <code>second()</code> 方法在 <code>first()</code> 方法之后被执行，<code>third()</code> 方法在 <code>second()</code> 方法之后被执行。</p>

<p><strong>提示：</strong></p>

<ul>
	<li>尽管输入中的数字似乎暗示了顺序，但是我们并不保证线程在操作系统中的调度顺序。</li>
	<li>你看到的输入格式主要是为了确保测试的全面性。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>"firstsecondthird"
<strong>解释：</strong>
有三个线程会被异步启动。输入 [1,2,3] 表示线程 A 将会调用 first() 方法，线程 B 将会调用 second() 方法，线程 C 将会调用 third() 方法。正确的输出是 "firstsecondthird"。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,2]
<strong>输出：</strong>"firstsecondthird"
<strong>解释：</strong>
输入 [1,3,2] 表示线程 A 将会调用 first() 方法，线程 B 将会调用 third() 方法，线程 C 将会调用 second() 方法。正确的输出是 "firstsecondthird"。</pre>

<p>&nbsp;</p>

<ul>
</ul>
<strong>提示：</strong>

<ul>
	<li><code>nums</code> 是 <code>[1, 2, 3]</code> 的一组排列</li>
</ul>


## 题解

### cpp [🔗](print-in-order.cpp) 
```cpp
class Foo {
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        first_ok_ = true;
        cv_.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lk(mu_);
        cv_.wait(lk, [this](){ return first_ok_; });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        second_ok_ = true;
        lk.unlock();
        cv_.notify_one();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lk(mu_);
        cv_.wait(lk, [this](){ return second_ok_; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
private:
    bool first_ok_ = false;
    bool second_ok_ = false;
    std::mutex mu_;
    std::condition_variable cv_;
};
```
### c [🔗](print-in-order.c) 
```c
typedef struct {
    // User defined data may be declared here.
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    bool first_ok;
    bool second_ok;
} Foo;

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    

    // Initialize user defined data here.
    obj->first_ok = false;
    obj->second_ok = false;
    pthread_mutex_init(&obj->mutex, NULL);
    pthread_cond_init(&obj->cond, NULL);
    return obj;
}

void first(Foo* obj) {
    
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();

    
    obj->first_ok = true;
    pthread_cond_broadcast(&obj->cond);
}

void second(Foo* obj) {
    pthread_mutex_lock(&obj->mutex);
    while (!obj->first_ok) {
        pthread_cond_wait(&obj->cond, &obj->mutex);
    }
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();

    obj->second_ok = true;
    pthread_mutex_unlock(&obj->mutex);
    pthread_cond_signal(&obj->cond);
}

void third(Foo* obj) {
    pthread_mutex_lock(&obj->mutex);
    while (!obj->second_ok) {
        pthread_cond_wait(&obj->cond, &obj->mutex);
    }
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
    pthread_mutex_unlock(&obj->mutex);

}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    if (obj != NULL) {
        pthread_mutex_destroy(&obj->mutex);
        pthread_cond_destroy(&obj->cond);
        free(obj);
    }
}
```


## 相关话题

- [多线程](../../tags/concurrency.md) 


## 相似题目

- [交替打印 FooBar](../print-foobar-alternately/README.md)  [Medium] 


## Links

- [Prev](../print-foobar-alternately/README.md) 
- [Next](../design-bounded-blocking-queue/README.md) 

