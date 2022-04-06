// @Title: Intersection of Two Arrays
// @Author: colinjxc
// @Date: 2021-05-23T16:45:29+08:00
// @URL: https://leetcode-cn.com/problems/intersection-of-two-arrays


func intersection(nums1 []int, nums2 []int) []int {
	numMap1 := make(map[int]struct{})
	resMap := make(map[int]struct{})
	var res []int
	for _, n := range nums1 {
		numMap1[n] = struct{}{}
	}
	for _, n := range nums2 {
		if _, e := numMap1[n]; e {
			if _, e := resMap[n]; !e {
				res = append(res, n)
				resMap[n] = struct{}{}
			}
		}
	}
	return res
}

