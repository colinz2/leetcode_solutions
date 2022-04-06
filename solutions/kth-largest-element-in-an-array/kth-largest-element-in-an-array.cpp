// @Title: Kth Largest Element in an Array
// @Author: colinjxc
// @Date: 2022-02-07T01:42:31+08:00
// @URL: https://leetcode-cn.com/problems/kth-largest-element-in-an-array


class Solution {
private:
    int FindKthLargest_(vector<int> &nums, int k,  int l, int r) {
        if (l >= r) {
            return nums[l];
        }

        int p = Partition(nums, l, r);
        if (p < k) {
            return FindKthLargest_(nums, k, p + 1, r);
        } else if (p > k) {
            return FindKthLargest_(nums, k, l, p - 1);
        } else {
            return nums[p];
        }
    }
    
    int Partition(vector<int> &nums, int l, int r) {
        int ri = random() % (r - l) + l;
        std::swap(nums[l], nums[ri]);

        int pv = nums[l];
        int p = l;

        for (int i = l + 1; i <= r; i++) {
            if (nums[i] > pv) {
                std::swap(nums[++p], nums[i]);
            }
        }
        std::swap(nums[p], nums[l]);
        return p;
    }
    
public:
    int findKthLargest(vector<int> &nums, int k) {
        int r = FindKthLargest_(nums, k - 1, 0, nums.size() - 1);
        return r;
    }
};
