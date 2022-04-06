// @Title: Distribute Candies
// @Author: colinjxc
// @Date: 2022-02-05T04:17:16+08:00
// @URL: https://leetcode-cn.com/problems/distribute-candies


class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> set(candyType.begin(), candyType.end());
        return std::min(set.size(), candyType.size()/2);    
    }
};
