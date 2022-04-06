// @Title: Intersection of Two Arrays II
// @Author: colinjxc
// @Date: 2018-12-05T15:57:31+08:00
// @URL: https://leetcode-cn.com/problems/intersection-of-two-arrays-ii


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        multiset<int> record;
        for(int num: nums1)
            record.insert(num);

        multiset<int> result;
        for(int num: nums2){
            multiset<int>::iterator iter = record.find(num);
            if( iter != record.end()){
                result.insert(num);
                record.erase(iter);
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};
