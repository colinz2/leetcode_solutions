// @Title: Traffic Light Controlled Intersection
// @Author: colinjxc
// @Date: 2022-02-11T03:38:35+08:00
// @URL: https://leetcode-cn.com/problems/traffic-light-controlled-intersection


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
