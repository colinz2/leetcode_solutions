// @Title: Fizz Buzz Multithreaded
// @Author: colinjxc
// @Date: 2022-02-11T01:16:44+08:00
// @URL: https://leetcode-cn.com/problems/fizz-buzz-multithreaded


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
