// @Title: Intersection of Two Arrays
// @Author: colinjxc
// @Date: 2018-12-05T14:17:18+08:00
// @URL: https://leetcode-cn.com/problems/intersection-of-two-arrays


class Solution:
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        a = set(nums1)
        b = set(nums2)
        c = a & b
        return list(c)
        
