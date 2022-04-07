
# [](https://leetcode-cn.com/problems/traffic-light-controlled-intersection)

## 题目描述



## 题解

### cpp [🔗](traffic-light-controlled-intersection.cpp) 
```cpp
class TrafficLight {
public:
    TrafficLight() {
      road1_is_green_ = true;
    }

    void carArrived(
        int carId,                   // ID of the car
        int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction,               // Direction of the car
        function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
        function<void()> crossCar    // Use crossCar() to make car cross the intersection
    ) {
        if (road1_is_green_ ^ (roadId == 2)) {
          crossCar();
        } else {
          std::unique_lock<std::mutex> lk(mu_);
          road1_is_green_ = !road1_is_green_;
          turnGreen();
          lk.unlock();
          crossCar();
        }
    }
private:
  bool road1_is_green_;
  std::mutex mu_;
};
```
### python3 [🔗](traffic-light-controlled-intersection.py) 
```python3
class TrafficLight:
    def __init__(self):
        from threading import Lock
        self.lock = Lock()
        self.green_road_id = 1

    def carArrived(
        self,
        carId: int,                      # ID of the car
        roadId: int,                     # ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        direction: int,                  # Direction of the car
        turnGreen: 'Callable[[], None]', # Use turnGreen() to turn light to green on current road
        crossCar: 'Callable[[], None]'   # Use crossCar() to make car cross the intersection
    ) -> None:
        
        if self.green_road_id == roadId:
          crossCar()
        else:
          self.lock.acquire()
          self.green_road_id = roadId
          turnGreen()
          crossCar()
          self.lock.release()
```


## 相关话题



## 相似题目



## Links

- [Prev](../check-if-it-is-a-straight-line/README.md) 
- [Next](../convert-binary-number-in-a-linked-list-to-integer/README.md) 

