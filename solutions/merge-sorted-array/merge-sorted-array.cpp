// @Title: Merge Sorted Array
// @Author: colinjxc
// @Date: 2018-11-28T16:40:18+08:00
// @URL: https://leetcode-cn.com/problems/merge-sorted-array


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        assert(nums1.size() == m + n && nums2.size() == n);

        for(int i = n + m - 1 ; i >= n ; i -- )
            nums1[i] = nums1[i - n];

        int i = n;  // pointer for nums1 [n, n+m)
        int j = 0;  // pointer for nums2 [0, n)
        int k = 0;  // pointer merged nums1 [0, n+m)
        while( k < n + m ){
            if( i >= n+m )
                nums1[k++] = nums2[j++];
            else if( j >= n )
                nums1[k++] = nums1[i++];
            else if( nums1[i] < nums2[j] )
                nums1[k++] = nums1[i++];
            else
                nums1[k++] = nums2[j++];
        }
    }
};

