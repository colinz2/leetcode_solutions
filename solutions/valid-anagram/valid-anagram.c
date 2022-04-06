// @Title: Valid Anagram
// @Author: colinjxc
// @Date: 2022-01-30T02:01:08+08:00
// @URL: https://leetcode-cn.com/problems/valid-anagram


bool is_all_zero(int *array, int len) {
    for (int i = 0; i < len; i++) {
        if (array[i] != 0) return false;
    }
    return true;
}

bool isAnagram(char * s, char * t){
    int find[256] = {0};
    int s_len = 0, t_len = 0;

    if (s == NULL || t == NULL)
        return false;

    while (*s != '\0') {
        find[*s++ - 'a']++;
        s_len++;
    }
    while (*t != '\0') {
        find[*t++ - 'a']--;
        t_len++;
    } 
    return s_len == t_len && is_all_zero(find, 26);
}
