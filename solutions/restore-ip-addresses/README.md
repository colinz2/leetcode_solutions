
# [](https://leetcode-cn.com/problems/restore-ip-addresses)

## 题目描述



## 题解

### cpp [🔗](restore-ip-addresses.cpp) 
```cpp
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> ip;
        if (s.size() < 4 || s.size() > 12) return res;
        solve(s, 0, ip, res);
        return res;
    }

private:
    void solve(string s, int index, vector<string> &ip, vector<string> &res) {
        if (index == s.size()) {
            if (ip.size() == 4) {
                string ip_addr = ip[0] + "." + ip[1] + "." + ip[2] + "." + ip[3];
                res.push_back(ip_addr);
            }
            return;
        }
        for (int step = 1; step <= 3; step++) {
            //s.size() - index is the lefted chars count,  the rule :
            //e.g.
            //have restored 1 of 4 ip number, the lefted chars count must less than 9 "3*(4 - 1)"
            if (3 * (4 - ip.size())  < s.size() - index) {
                //cout << "\U0001f602\U0001f602\U0001f602\U0001f602" << endl;
                break;
            }
            if (index + step > s.size()) {
                break;
            }
            //first byte can't be 0, if string size longer than 1
            if (step > 1 && s[index] == '0') {
                continue;
            }
            string tmp = s.substr(index, step);
            int num = stoi(tmp);
            if (num >= 0 && num <= 255) {
                ip.push_back(tmp);
                solve(s, index + step, ip, res);
                ip.pop_back();
            }
        }
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../reverse-linked-list-ii/README.md) 
- [Next](../binary-tree-inorder-traversal/README.md) 

