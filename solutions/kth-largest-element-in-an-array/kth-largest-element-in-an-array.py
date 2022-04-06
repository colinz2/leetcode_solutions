// @Title: Kth Largest Element in an Array
// @Author: colinjxc
// @Date: 2021-11-02T23:54:50+08:00
// @URL: https://leetcode-cn.com/problems/kth-largest-element-in-an-array


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def partition(nums, l, r) -> int:
            xx = random.randint(l, r)
            nums[xx], nums[l] = nums[l], nums[xx]
 
            p = l + 1
            for index in range(l+1, r+1):
                # 降序排序，如果发现大的就交换
                if nums[index] > nums[l]:
                    nums[p], nums[index] = nums[index], nums[p]
                    p = p + 1
            # 这块要注意啊，是 p - 1
            nums[p - 1], nums[l] = nums[l], nums[p -1]
            return p-1

    
        def findKth(nums, l, r, k) -> int:
            if l == r:
                return nums[l]

            p = partition(nums, l, r)                
            if p > k :
                return findKth(nums, l, p-1, k)
            elif p < k :
                return findKth(nums, p+1, r, k)
            return nums[k]


        return findKth(nums, 0, len(nums)-1, k -1)

        

    
