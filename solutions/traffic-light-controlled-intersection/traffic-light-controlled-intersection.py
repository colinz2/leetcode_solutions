// @Title: Traffic Light Controlled Intersection
// @Author: colinjxc
// @Date: 2022-02-11T03:51:05+08:00
// @URL: https://leetcode-cn.com/problems/traffic-light-controlled-intersection


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
