// @Title: Unique Morse Code Words
// @Author: colinjxc
// @Date: 2018-12-15T14:23:03+08:00
// @URL: https://leetcode-cn.com/problems/unique-morse-code-words


class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string morse_code[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> unique_ms;
        for (string& word : words) {
            string morse_string = "";
            for (int i = 0; i < word.size(); i++) {
                morse_string += morse_code[word[i] - 'a'];
            }
            unique_ms.insert(morse_string);
        }
        
        return unique_ms.size();
    }
};
