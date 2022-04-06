// @Title: Building H2O
// @Author: colinjxc
// @Date: 2022-02-12T15:15:08+08:00
// @URL: https://leetcode-cn.com/problems/building-h2o


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
