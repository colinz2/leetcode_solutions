// @Title: Kth Largest Element in an Array
// @Author: colinjxc
// @Date: 2022-02-07T01:55:48+08:00
// @URL: https://leetcode-cn.com/problems/kth-largest-element-in-an-array


// 降序
func partioin(nums []int, l int,  r int) int {
    ri := rand.Intn(r-l) % (r-l) + l
    nums[ri], nums[l] = nums[l],nums[ri]
    pv := nums[l]

    i, j := l + 1, r
    for {
        for nums[i] > pv && i < r {
            i++
        }
        for nums[j] < pv && j > l {
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
