// @Title: Print Zero Even Odd
// @Author: colinjxc
// @Date: 2022-02-12T15:29:57+08:00
// @URL: https://leetcode-cn.com/problems/print-zero-even-odd


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
