// @Title: Occurrences After Bigram
// @Author: colinjxc
// @Date: 2019-10-03T13:39:25+08:00
// @URL: https://leetcode-cn.com/problems/occurrences-after-bigram


class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        text.push_back(' ');
        vector<string> vRes;
        string sFirst,sSecond,sTemp;
        for(int i=0;i<text.size();i++){
            if(text[i]!=' '){
                sTemp.push_back(text[i]);
            }else{
                if(!sFirst.empty()&&!sSecond.empty()){
                    if((sFirst==first)&&(sSecond==second)){
                        vRes.push_back(sTemp);
                    }
                }
                sFirst=sSecond;
                sSecond=sTemp;
                sTemp.clear();
            }
        }
        return vRes;
    }
};
