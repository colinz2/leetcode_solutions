
# [交替打印字符串](https://leetcode-cn.com/problems/fizz-buzz-multithreaded)

## 题目描述

<p>编写一个可以从 1 到 n 输出代表这个数字的字符串的程序，但是：</p>

<ul>
	<li>如果这个数字可以被 3 整除，输出 "fizz"。</li>
	<li>如果这个数字可以被 5 整除，输出 "buzz"。</li>
	<li>如果这个数字可以同时被 3 和 5 整除，输出 "fizzbuzz"。</li>
</ul>

<p>例如，当 <code>n = 15</code>，输出： <code>1, 2, fizz, 4, buzz, fizz, 7, 8, fizz, buzz, 11, fizz, 13, 14, fizzbuzz</code>。</p>

<p>假设有这么一个类：</p>

<pre>
class FizzBuzz {
  public FizzBuzz(int n) { ... }               // constructor
  public void fizz(printFizz) { ... }          // only output "fizz"
  public void buzz(printBuzz) { ... }          // only output "buzz"
  public void fizzbuzz(printFizzBuzz) { ... }  // only output "fizzbuzz"
  public void number(printNumber) { ... }      // only output the numbers
}</pre>

<p>请你实现一个有四个线程的多线程版  <code>FizzBuzz</code>， 同一个 <code>FizzBuzz</code> 实例会被如下四个线程使用：</p>

<ol>
	<li>线程A将调用 <code>fizz()</code> 来判断是否能被 3 整除，如果可以，则输出 <code>fizz</code>。</li>
	<li>线程B将调用 <code>buzz()</code> 来判断是否能被 5 整除，如果可以，则输出 <code>buzz</code>。</li>
	<li>线程C将调用 <code>fizzbuzz()</code> 来判断是否同时能被 3 和 5 整除，如果可以，则输出 <code>fizzbuzz</code>。</li>
	<li>线程D将调用 <code>number()</code> 来实现输出既不能被 3 整除也不能被 5 整除的数字。</li>
</ol>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>本题已经提供了打印字符串的相关方法，如 <code>printFizz()</code> 等，具体方法名请参考答题模板中的注释部分。</li>
</ul>

<p> </p>


## 题解

### cpp [🔗](fizz-buzz-multithreaded.cpp) 
```cpp
class FizzBuzz {
private:
    int n;
    int status;
    int index;
    std::mutex m1;
    std::condition_variable cv1;
public:
    FizzBuzz(int n) {
        this->n = n;
        this->index = 1;
        this->status = 0;
    }

    int NextStatus() {
        int curr = ++index;
        if (curr > n) return -1;
        else if (curr % 15 == 0) return 15;
        else if (curr % 5 == 0) return 5;
        else if (curr % 3 == 0) return 3;
        else return 0;
    }

    void Loop(function<void()> print, function<bool()> cmp) {
        for (;;) {
            std::unique_lock<std::mutex> lk(m1);
            cv1.wait(lk, [&] {
                return cmp() || (index > n);
            });
            if (index > n) {
                cv1.notify_all();
                break;
            }
            print();

            status = NextStatus();
            lk.unlock();
            cv1.notify_all();
        }
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        Loop(printFizz, [this]{ 
            return status == 3;
        });
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        Loop(printBuzz, [this]{ 
            return status == 5;
        });
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        Loop(printFizzBuzz, [this]{ 
            return status == 15;
        });
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        Loop([&]{
            printNumber(index);
        }, [this]{ 
            return status != 5 && status != 3 && status != 15;
        });
    }
};
```
### c [🔗](fizz-buzz-multithreaded.c) 
```c
typedef struct {
    int n;
    pthread_barrier_t barrier;
} FizzBuzz;

FizzBuzz* fizzBuzzCreate(int n) {
    FizzBuzz* obj = (FizzBuzz*) malloc(sizeof(FizzBuzz));
    obj->n = n;
    pthread_barrier_init(&obj->barrier, NULL, 4);
    return obj;
}

// printFizz() outputs "fizz".
void fizz(FizzBuzz* obj) {
    for (int i = 1; i <= obj->n; i++) {
      if (i%3 == 0 && i%5 != 0) {
        printFizz();
      }
      pthread_barrier_wait(&obj->barrier);
    }
}

// printBuzz() outputs "buzz".
void buzz(FizzBuzz* obj) {
    for (int i = 1; i <= obj->n; i++) {
      if (i%3 != 0 && i%5 == 0) {
        printBuzz();
      }
      pthread_barrier_wait(&obj->barrier);
    }
}

// printFizzBuzz() outputs "fizzbuzz".
void fizzbuzz(FizzBuzz* obj) {
    for (int i = 1; i <= obj->n; i++) {
      if (i%15 == 0) {
        printFizzBuzz();
      }
      pthread_barrier_wait(&obj->barrier);
    }
}

// You may call global function `void printNumber(int x)`
// to output "x", where x is an integer.
void number(FizzBuzz* obj) {
    for (int i = 1; i <= obj->n; i++) {
      if (i%3 != 0 && i%5 != 0) {
        printNumber(i);
      }
      pthread_barrier_wait(&obj->barrier);
    }
}

void fizzBuzzFree(FizzBuzz* obj) {
  if (obj) {
    pthread_barrier_destroy(&obj->barrier);
    free(obj);
  }   
}
```


## 相关话题

- [多线程](../../tags/concurrency.md) 


## 相似题目



## Links

- [Prev](../maximum-number-of-balloons/README.md) 
- [Next](../design-skiplist/README.md) 

