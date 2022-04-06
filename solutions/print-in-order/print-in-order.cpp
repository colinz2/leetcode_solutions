// @Title: Print in Order
// @Author: colinjxc
// @Date: 2022-03-04T01:36:07+08:00
// @URL: https://leetcode-cn.com/problems/print-in-order


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
