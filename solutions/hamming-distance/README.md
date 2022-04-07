
# [](https://leetcode-cn.com/problems/hamming-distance)

## 题目描述



## 题解

### c [🔗](hamming-distance.c) 
```c
int hammingDistance(int x, int y) {
    int z = x ^ y;
    int distance = 0;
    while (z > 0) {
        distance += z & 1;
        z = z >> 1;
    }
    return distance;
}
```
### cpp [🔗](hamming-distance.cpp) 
```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance = 0;
        int z = x ^ y;
        while (z) {
            distance += (z & 0x01);
            z >>= 1;
        }
        return distance;              
    }
};
```
### golang [🔗](hamming-distance.go) 
```golang
func hammingDistance(x int, y int) int {
	res := 0
	z := x ^ y
	for z != 0 {
		if z&1 == 1 {
			res++
		}
		z >>= 1
	}
	return res
}

```
### python3 [🔗](hamming-distance.py) 
```python3
class Solution:
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        xor = x ^ y
        d = 0
        while xor > 0:
            d += xor & 1
            xor >>= 1
        return d
        
```


## 相关话题



## 相似题目



## Links

- [Prev](../repeated-substring-pattern/README.md) 
- [Next](../validate-ip-address/README.md) 

