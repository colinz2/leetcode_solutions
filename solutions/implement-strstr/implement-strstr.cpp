// @Title: Implement strStr()
// @Author: colinjxc
// @Date: 2018-11-22T00:30:47+08:00
// @URL: https://leetcode-cn.com/problems/implement-strstr


class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size())
            return -1;

        for(int i = 0 ; i <= haystack.size() - needle.size() ; i ++){
            int j = 0;
            for(j = 0 ; j < needle.size() ; j ++)
                if(needle[j] != haystack[j + i])
                    break;
            if(j == needle.size())
                return i;
        }
        return -1;
    }
};
