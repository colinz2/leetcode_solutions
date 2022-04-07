
# [H2O 生成](https://leetcode-cn.com/problems/building-h2o)

## 题目描述

<p>现在有两种线程，氧 <code>oxygen</code> 和氢 <code>hydrogen</code>，你的目标是组织这两种线程来产生水分子。</p>

<p>存在一个屏障（barrier）使得每个线程必须等候直到一个完整水分子能够被产生出来。</p>

<p>氢和氧线程会被分别给予 <code>releaseHydrogen</code> 和 <code>releaseOxygen</code> 方法来允许它们突破屏障。</p>

<p>这些线程应该三三成组突破屏障并能立即组合产生一个水分子。</p>

<p>你必须保证产生一个水分子所需线程的结合必须发生在下一个水分子产生之前。</p>

<p>换句话说:</p>

<ul>
	<li>如果一个氧线程到达屏障时没有氢线程到达，它必须等候直到两个氢线程到达。</li>
	<li>如果一个氢线程到达屏障时没有其它线程到达，它必须等候直到一个氧线程和另一个氢线程到达。</li>
</ul>

<p>书写满足这些限制条件的氢、氧线程同步代码。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入: </strong>water = "HOH"
<strong>输出: </strong>"HHO"
<strong>解释:</strong> "HOH" 和 "OHH" 依然都是有效解。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入: </strong>water = "OOHHHH"
<strong>输出: </strong>"HHOHHO"
<strong>解释:</strong> "HOHHHO", "OHHHHO", "HHOHOH", "HOHHOH", "OHHHOH", "HHOOHH", "HOHOHH" 和 "OHHOHH" 依然都是有效解。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 * n == water.length</code></li>
	<li><code>1 &lt;= n &lt;= 20</code></li>
	<li><code>water[i] == 'O' or 'H'</code></li>
	<li>输入字符串&nbsp;<code>water</code>&nbsp;中的 <font color="#c7254e"><font face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size:12.6px"><span style="background-color:#f9f2f4">'H'</span></span></font></font>&nbsp;总数将会是 <code>2 * n</code> 。</li>
	<li>输入字符串&nbsp;<code>water</code>&nbsp;中的 <font color="#c7254e"><font face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size:12.6px"><span style="background-color:#f9f2f4">'O'</span></span></font></font>&nbsp;总数将会是 <code>n</code> 。</li>
</ul>


## 题解

### cpp [🔗](building-h2o.cpp) 
```cpp
class H2O {
public:
    H2O() {
      hydrogen_left_ = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lk(mu_);
        cv_.wait(lk, [this]{ return hydrogen_left_ < 2; });
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        hydrogen_left_++;
        lk.unlock();
        cv_.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lk(mu_);
        cv_.wait(lk, [this]{ return hydrogen_left_ == 2; });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        hydrogen_left_ = 0;
        lk.unlock();
        cv_.notify_all();
    }
private:
  std::mutex mu_;
  std::condition_variable cv_;
  int hydrogen_left_;
};
```
### c [🔗](building-h2o.c) 
```c
typedef struct {
    // User defined data may be declared here.
    pthread_mutex_t mu;
    pthread_cond_t cond;
    int h_left;
} H2O;

H2O* h2oCreate() {
    H2O* obj = (H2O*) malloc(sizeof(H2O));
    
    // Initialize user defined data here.
    obj->h_left = 0;
    pthread_mutex_init(&obj->mu, NULL);
    pthread_cond_init(&obj->cond, NULL);
    return obj;
}

void hydrogen(H2O* obj) {
    pthread_mutex_lock(&obj->mu);
    while (obj->h_left == 2) {
      pthread_cond_wait(&obj->cond, &obj->mu);
    }
    // releaseHydrogen() outputs "H". Do not change or remove this line.
    releaseHydrogen();
    obj->h_left++;
    pthread_cond_broadcast(&obj->cond);
    pthread_mutex_unlock(&obj->mu);
}

void oxygen(H2O* obj) {
    pthread_mutex_lock(&obj->mu);
    while (obj->h_left < 2) {
        pthread_cond_wait(&obj->cond, &obj->mu);
    }
    // releaseOxygen() outputs "O". Do not change or remove this line.
    releaseOxygen();
    obj->h_left = 0;
    pthread_cond_broadcast(&obj->cond);
    pthread_mutex_unlock(&obj->mu);
}

void h2oFree(H2O* obj) {
    // User defined data may be cleaned up here.
    if (obj) {
      pthread_mutex_destroy(&obj->mu);
      pthread_cond_destroy(&obj->cond);
      free(obj);
    }
}
```


## 相关话题

- [多线程](../../tags/concurrency.md) 


## 相似题目



## Links

- [Prev](../occurrences-after-bigram/README.md) 
- [Next](../print-foobar-alternately/README.md) 

