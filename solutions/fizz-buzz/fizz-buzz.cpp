// @Title: Fizz Buzz
// @Author: colinjxc
// @Date: 2018-10-16T13:36:34+08:00
// @URL: https://leetcode-cn.com/problems/fizz-buzz


class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        //c++ std::to_string
        for (int i = 1; i <= n; i++){
            if (i%15 == 0) result.push_back("FizzBuzz");
            else if (i%3 == 0) result.push_back("Fizz");
            else if (i%5 == 0) result.push_back("Buzz");
            else result.push_back(to_string(i));
        }
        
        return result;
    }
};
