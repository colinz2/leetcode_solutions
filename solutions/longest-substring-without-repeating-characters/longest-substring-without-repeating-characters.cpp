// @Title: Longest Substring Without Repeating Characters
// @Author: colinjxc
// @Date: 2022-01-23T16:59:56+08:00
// @URL: https://leetcode-cn.com/problems/longest-substring-without-repeating-characters


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool exists[256] = {false};
        int left = 0, right = 0;
        int max_len = 0;

        while (right < s.size()) {
            int next = s[right];
            if (!exists[next]) {
                exists[s[right]] = true;
                max_len = std::max(max_len, right - left + 1);
                right++;
            } else {
                exists[s[left]] = false;
                left++;
            }
        }
        return max_len;
    }
};
