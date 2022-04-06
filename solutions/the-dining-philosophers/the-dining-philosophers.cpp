// @Title: The Dining Philosophers
// @Author: colinjxc
// @Date: 2022-02-10T20:52:39+08:00
// @URL: https://leetcode-cn.com/problems/the-dining-philosophers


class DiningPhilosophers {
public:
    DiningPhilosophers() {
    }
    
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

        int l = philosopher, r = (philosopher + 1) % 5;
        if (philosopher %2 == 0){
            lock[r].lock();
            lock[l].lock();
            pickLeftFork();
            pickRightFork();
        } else {
            lock[l].lock();
            lock[r].lock();
            pickLeftFork();
            pickRightFork();
        }
        
        eat();
        putLeftFork();
        putRightFork();
        lock[l].unlock();
        lock[r].unlock();
    }
private:
    std::mutex lock[5];
};

