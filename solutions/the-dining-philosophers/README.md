
# [](https://leetcode-cn.com/problems/the-dining-philosophers)

## 题目描述



## 题解

### cpp [🔗](the-dining-philosophers.cpp) 
```cpp
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

```


## 相关话题



## 相似题目



## Links

- [Prev](../design-skiplist/README.md) 
- [Next](../check-if-it-is-a-straight-line/README.md) 

