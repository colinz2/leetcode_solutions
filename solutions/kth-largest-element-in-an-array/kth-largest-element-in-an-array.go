// @Title: Kth Largest Element in an Array
// @Author: realzhangm
// @Date: 2021-11-02T22:57:33+08:00
// @URL: https://leetcode-cn.com/problems/kth-largest-element-in-an-array


// 降序
func partioin(nums []int, l, r int) int {
    pv := nums[l]
    i, j := l + 1, r

    for {
        for nums[i] > pv && i < r {
            i++
        }
        for nums[j] < pv && j >= l + 1 {
            j--
        }

        if i >= j {
            break
        }
        
        nums[i], nums[j] = nums[j], nums[i]
        i++
        j--
    }
    nums[l], nums[j] = nums[j], nums[l]
    return j
}

func findKthLargest0(nums []int, k, l, r int) int {
    if l == r {
        return nums[k]
    }

    p := partioin(nums, l, r)
    if (p > k) {
        return findKthLargest0(nums, k, l, p - 1)
    } else if (p < k) {
        return findKthLargest0(nums, k, p + 1, r)
    } else {
        return nums[p]
    }
}


func findKthLargest(nums []int, k int) int {
    return findKthLargest0(nums, k-1, 0, len(nums) - 1)
}


