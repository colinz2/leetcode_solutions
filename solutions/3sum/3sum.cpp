// @Title: 3Sum
// @Author: colinjxc
// @Date: 2022-01-24T18:56:35+08:00
// @URL: https://leetcode-cn.com/problems/3sum


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        if (nums.size() == 0) return ret;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            int target = -nums[i];
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    ret.push_back({nums[i], nums[l], nums[r]});
                    //哈哈\U0001f604
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                } else if (nums[l] + nums[r] > target) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ret;
    }
};
