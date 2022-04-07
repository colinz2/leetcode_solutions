
# [](https://leetcode-cn.com/problems/fizz-buzz-multithreaded)

## 题目描述



## 题解

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


## 相关话题



## 相似题目



## Links

- [Prev](../maximum-number-of-balloons/README.md) 
- [Next](../design-skiplist/README.md) 

