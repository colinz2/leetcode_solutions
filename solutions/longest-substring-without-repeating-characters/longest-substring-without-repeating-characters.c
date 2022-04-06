// @Title: Longest Substring Without Repeating Characters
// @Author: colinjxc
// @Date: 2022-01-23T19:14:04+08:00
// @URL: https://leetcode-cn.com/problems/longest-substring-without-repeating-characters


int lengthOfLongestSubstring(char * s){
    int left = 0;
    int right = 0;
    int max_len = 0;

    bool exist[256] = {false,};

    while (*(s+right)) {
        if (!exist[*(s+right)]) {
            exist[*(s+right)] = true;
            if (right - left + 1 > max_len) {
                max_len = right - left + 1;
            }
            right++;
        } else {
            exist[*(s+left)] = false;
            left++;
        }
    }
    return max_len;
}
